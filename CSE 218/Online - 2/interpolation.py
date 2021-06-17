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

# Manual Input from User for V = 28 
X_vals = [22,25,27,30]
Y_vals = [44,43,42,40]

P28_3 = lagrangian_interpolation(X_vals,Y_vals,28)
print("Pressure at V= 28 is: ", P28_3)
P28_2 = lagrangian_interpolation([25,27,30], [43,42,40], 28)
eps_a = (abs(P28_3- P28_2)/P28_3)*100
print("Relative Appx Error: ", eps_a)

# Manual Input from User for V = 32 
X_vals = [30,31,35,37]
Y_vals = [40,35,30,25]

P32_3 = lagrangian_interpolation(X_vals,Y_vals,32)
print("Pressure at V= 32 is: ", P32_3)
P32_2 = lagrangian_interpolation([30,31,35], [40,35,30], 32)
eps_a = (abs(P32_3- P32_2)/P32_3)*100
print("Relative Appx Error: ", eps_a)