def L_W(i, X_vals, x):
    prod = 1
    for j in range(len(X_vals)):
        if j!=i:
            prod *= (x - X_vals[j])/(X_vals[i] - X_vals[j])
    return prod

def lagrangian_interpolation(X_vals, Y_vals, x):
    val = 0
    for i in range(len(Y_vals)):
        val += L_W(i, X_vals, x) * Y_vals[i]
    return val

X_vals = [10,15,20,22.5]
Y_vals = [227.04, 362.78, 517.35, 602.97]


print(lagrangian_interpolation(X_vals,Y_vals,16))