#python bisection.py
import math
import numpy as np;
import matplotlib.pyplot as plt

f = lambda x: (x / (1-x)) * math.sqrt(6/(2+x)) - 0.05

def bisection(xl,xr,Es,max_iteration):
    xl = float(xl);xr = float(xr);Es = float(Es);max_iteration = int(max_iteration)
    if(f(xl)*f(xr) >= 0):
        print("Invalid Input")
    xm_old = (xl + xr) #random value
    for i in range(max_iteration):
        xm = (xl + xr)/2
        Sign = f(xm) * f(xl)
        Ea = abs((xm - xm_old)/xm)*100
        xm_old = xm
        if i != 0:
            print(i+1,"      ",xm,"     ",Ea)
        else:
            print(i+1,"      ",xm,"         -",)

        if (Sign == 0) or (Ea < Es):
            break
        elif (Sign < 0):
            xr = xm
        else:
            xl = xm


    return xm

ans = bisection(0.1,0.5,0.000005,10000)
print(ans)

#plotting data on matplotlib

plt.title("Visualizing f(x)")
plt.xlabel("X")
plt.ylabel("Y")

plt.axis = [-2,4]
Xarr = np.linspace(-1.9,3.5,100)
lst = list()
for i in Xarr:
    y = f(i)
    lst.append(y)
Yarr = np.array(lst)
plt.plot(Xarr,Yarr, 'b',label= 'f(x)')
plt.plot(np.array([-2.5,4.5]),np.array([0,0]),'r')
plt.show()
