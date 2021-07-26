import math
import numpy as np;
import matplotlib.pyplot as plt


T = 19+273.15
def f(x):
    return T*(1.129241e-3 + 2.341077e-4* math.log(x) +  8.775468e-8* (math.log(x)**3))- 1



#plotting data on matplotlib
fig, ax = plt.subplots()
ax.set_title("Visualizing f(x)")
ax.set_xlabel("X")
ax.set_ylabel("Y")

Xarr = np.linspace(0.1,20000,1000)
lst = list()
for i in Xarr:
    y = f(i)
    lst.append(y)
Yarr = np.array(lst)

ax.plot(Xarr,Yarr, 'b',label= 'f(x)')
ax.grid(True, which='both')
ax.axhline(y=0, color='k')
ax.axvline(x=0, color='k')
plt.show()



def bisection(xl, xr, err_tol, max_ittr):
    # initial values check
    if(f(xl) * f(xr) >= 0):
        print("Invalid values.")
        return
    xm_old = xl+ xr # random value
    for i in range(max_ittr):
        xm = 0.5*(xl + xr)
        apx_err = abs((xm - xm_old)/xm)
        xm_old = xm
        
        if f(xm) ==0 or apx_err <= err_tol:
            break
        elif f(xm) * f(xl) > 0:
            xl = xm
        else:
            xr = xm
    return xm


#value is between 13000 and 13500
XL = float(input("Enter the lower value:  "))
XU = float(input("Enter the upper value:  "))

print("Resistance is :", bisection(XL,XU,0.000005,10000))