import numpy as np

def div_diff(X_vals,Y_vals):
    n = len(Y_vals)
    coef = np.zeros([n, n])
    coef[:,0] = Y_vals  # first column in y0, y1, y2,....

    for j in range(1,n):
        for i in range(n-j):
            coef[i][j] = (coef[i+1][j-1] - coef[i][j-1]) / (X_vals[i+j]-X_vals[i])
            
    return coef

def interpolated_value(B, X_vals, x):
    val = 0 
    for i in range(len(B)):
        prod = 1
        for j in range(i):
            prod *= (x - X_vals[j])
        val += B[i] * prod
    return val 

# Manual Input from User
X_vals = [10,15,20,22.5]
Y_vals = [227.04, 362.78, 517.35, 602.97]

print(div_diff(X_vals, Y_vals))
B = div_diff(X_vals, Y_vals)[0]    #B0, B1, B2,...,Bn
print(B)


print(interpolated_value(B, X_vals, 16))

