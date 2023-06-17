#include <iostream>
#include <sstream>

int main() {
	int num;
	std::string input;
	std::stringstream stream;

	std::cin >> input;

	if (input[0] != '0') {
		stream.str(input.substr(0));
		stream >> std::dec >> num;
	}
	else {
		if (input[1] == 'x') {
			stream.str(input.substr(2));
			stream >> std::hex >> num;
		}
		else {
			stream.str(input.substr(1));
			stream >> std::oct >> num;
		}
	}

	std::cout << num;

	return 0;
}