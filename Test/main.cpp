#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stack>
#include <cmath>
#include <queue>
#include <random>
#include <thread>
#include <chrono>
#include <mutex>
#include <windows.h>
#include <psapi.h>
#include <TlHelp32.h>
using namespace std;

bool ProgramRunning = false;

int RNG(int start, int end) {
	random_device rd;

	mt19937 gen(rd());

	uniform_int_distribution<int> dis(start, end);

	return dis(gen);
}

void testTheProgram(string name, string *consumedTime) {
	mutex mtx;

	string instuction = name + " < input.txt" + " > output.txt";
	chrono::high_resolution_clock::time_point beginTime = chrono::high_resolution_clock::now();
	system(instuction.c_str());
	chrono::high_resolution_clock::time_point endTime = chrono::high_resolution_clock::now();
	ProgramRunning = false;

	chrono::duration<double> diff = endTime - beginTime;
	
	ostringstream oss;

	oss << chrono::duration_cast<chrono::milliseconds>(diff).count();

	*consumedTime = oss.str();
}

char* ConvertWCtoC(wchar_t* str) {
	char* pStr;
	int strSize = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);
	pStr = new char[strSize];
	WideCharToMultiByte(CP_ACP, 0, str, -1, pStr, strSize, 0, 0);

	return pStr;
}

BOOL Search_Pid(const char* szProcessName, DWORD &PID) {
	HANDLE hndl = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	DWORD dwsma = GetLastError();

	PROCESSENTRY32 procEntry = { 0 };
	procEntry.dwSize = sizeof(PROCESSENTRY32);
	Process32First(hndl, &procEntry);

	while (1) {
		char* tmp = ConvertWCtoC(procEntry.szExeFile);
		if (!strcmp(tmp, szProcessName)) {
			PID = procEntry.th32ProcessID;
			CloseHandle(hndl);
			delete tmp;
			return TRUE;
		}
		delete tmp;
		if (!Process32Next(hndl, &procEntry)) {
			return FALSE;
		}
	}

	CloseHandle(hndl);
	return FALSE;
}

void getResourceUseage(string name, SIZE_T *memoryUseage) {
	mutex mtx;
	HANDLE hProcess = NULL;
	name += ".exe";
	wchar_t WName[256];
	mbstowcs(WName, name.c_str(), name.length());

	PROCESS_MEMORY_COUNTERS pmc;
	DWORD processID;

	do {
		if (!Search_Pid(name.c_str(), processID)) {
			mtx.lock();
			cout << "Failed to get PID" << '\n';
			mtx.unlock();
			continue;
		}

		hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);

		if (NULL == hProcess) {
			mtx.lock();
			cout << "Found no Process" << '\n';
			mtx.unlock();
		}
	} while (hProcess == NULL && ProgramRunning);

	while (ProgramRunning) {
		if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc))) {
			if (*memoryUseage < pmc.PeakPagefileUsage) {
				*memoryUseage = pmc.PeakPagefileUsage;
			}
			//mtx.lock();
			//cout << "\tPeakWorkingSetSize: " << pmc.PeakWorkingSetSize / 1024 << "KB\n";
			//cout << "\tWorkingSetSize: " << pmc.WorkingSetSize / 1024 << "KB\n";
			//cout << "\tPagefileUsage: " << pmc.PagefileUsage / 1024 << "KB\n";
			//cout << "\tPeakPagefileUsage: " << pmc.PeakPagefileUsage / 1024 << "KB\n";
			//mtx.unlock();
		}
	}

	CloseHandle(hProcess);
}

int main() {
	ofstream file;

	int N = 0, M = 0, K = 0, u = 0, v = 0, c = 0, d = 0;

	while (true) {
		file.open("input.txt");
		N = RNG(2, 100);
		M = RNG(0, 10000);
		K = RNG(0, 10000);

		file << '1' << '\n';
		file << N << ' ' << M << ' ' << K << '\n';

		for (int i = 0; i < K; i++) {
			do {
				u = RNG(1, N);
				v = RNG(1, N);
			} while (u == v);
			c = RNG(1, M);
			d = RNG(1, 1000);

			file << u << ' ' << v << ' ' << c << ' ' << d << '\n';
		}
		file.close();

		vector<thread> workers;

		SIZE_T memoryUseage = 0;
		string consumedTime;
		const char *PROGRAM_NAME = "10217";
		const int memoryLimit = 268435456; //256MB

		system("cls");
		ProgramRunning = true;
		workers.push_back(thread(testTheProgram, PROGRAM_NAME, &consumedTime));
		workers.push_back(thread(getResourceUseage, PROGRAM_NAME, &memoryUseage));

		workers[0].join();
		workers[1].join();

		cout << "Consumed Time : " << consumedTime << "ms" << '\n';
		cout << "Used Memory : " << memoryUseage / 1024 << "KB" << '\n';
		if (memoryUseage > memoryLimit) {
			cout << "메모리 초과!" << '\n';
			system("pause");
			break;
		}
	}
}