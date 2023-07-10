import sys
sys.setrecursionlimit(10**6)

N = int(input())
A = list(map(int, input().split()))
swap = 0

def sort(start, end):
    B = list()
    mid = (start + end)//2
    global swap
    temp = 0

    if end - start == 0:
        return
  
    elif end - start == 1:
        if A[start] > A[end]:
            A[start], A[end] = A[end], A[start]
            swap += 1
        return
    
    else:
        sort(start, mid)
        sort(mid + 1, end)

        i = start
        j = mid + 1
        while (True):
            if (i > mid and j > end):
               break

            elif (i > mid):
                B.append(A[j])
                j+=1

            elif (j > end):
                B.append(A[i])
                swap+=temp
                i+=1

            elif A[i] <= A[j]:
                B.append(A[i])
                swap+=temp
                i+=1

            else:
                B.append(A[j])
                temp+=1
                j+=1
        
        for i in B:
            A[start] = i
            start+=1
        
        return

sort(0, N-1)

print(swap)