ASize, BSize = input().split()
ASize = int(ASize)
BSize = int(BSize)
A = list(map(int, input().split()))
B = list(map(int, input().split()))

Ap = 0
Bp = 0
for i in range(ASize + BSize):
    if (Ap >= ASize):
        print(B[Bp], end=' ')
        Bp+=1
        continue
    if (Bp >= BSize):
        print(A[Ap], end=' ')
        Ap+=1
        continue
    if(A[Ap] > B[Bp]):
        print(B[Bp], end=' ')
        Bp+=1
    else:
        print(A[Ap], end=' ')
        Ap+=1