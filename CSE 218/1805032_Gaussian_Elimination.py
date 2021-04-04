#python 1805032_Gaussian_Elimination.py
import numpy as np
def GaussianElimination(A,B,d):
    d= bool(d)
    n = A.shape[0]

    for i in range(n):
        if(A[i][i] == 0):
            print("Error Occured, Diagonal Element is Zero")
        #for all next row
        for j in range(i+1,n):
            r = A[j][i] / A[i][i]
            #j tomo row er sobgula element update kora
            for k in range(n):
                A[j][k] = A[j][k] - r * A[i][k]
            B[j][0] = B[j][0] - r*B[i][0]
        if d:
            print("Forward Elemination: after", i+1, "th iteration:")
            print(A)
            print(B)
    #end of Forward Elemination
    for i in range(n-1,-1,-1):
        B[i][0] = B[i][0] / A[i][i]
        #uporer sobgula row er B update
        for j in range(j):
            B[j][0] = B[j][0] - A[j][i] * B[i][0]
    return B


n = int(input());
A = np.zeros((n,n));
B = np.zeros((n,1));

#inputing values
for i in range(n):
    line = input()
    line = line.split()
    for j in range(n):
        A[i][j] = float(line[j])

for i in range(n):
    B[i][0] = float(input())

X = GaussianElimination(A,B,1)
for i in range(n):
    print(X[i][0])
