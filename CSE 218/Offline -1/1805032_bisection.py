import math
import numpy as np;
import matplotlib.pyplot as plt
from prettytable import PrettyTable


f = lambda x: (x / (1-x)) * math.sqrt(6/(2+x)) - 0.05
#f = lambda x: x*x*x - 2400*(x*x) - 3*x +2

#plotting data on matplotlib
fig, ax = plt.subplots()
ax.set_title("Visualizing f(x)")
ax.set_xlabel("X")
ax.set_ylabel("Y")

Xarr = np.linspace(-1.9,0.99,1000)
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

def bisection(xl,xr,Es,max_iteration):
    xl = float(xl);xr = float(xr);Es = float(Es);max_iteration = int(max_iteration)
    if(f(xl)*f(xr) > 0):
        print("Invalid Input of Xl and Xu")
        return
    xm_old = xl + xr #random value
    for i in range(max_iteration):
        xm = (xl + xr)/2
        Sign = f(xm) * f(xl)
        Ea = abs((xm - xm_old)/xm)*100
        #updating
        xm_old = xm
        if (Sign == 0) or (Ea < Es):
            break
        elif (Sign < 0):
            xr = xm
        else:
            xl = xm
    return xm

def bisection2(xl,xr):
    xl = float(xl);xr = float(xr);
    table = PrettyTable(["Itteration","Xl","Xr","Xm","Abs Relative Appx Error"])
    if(f(xl)*f(xr) > 0):
        print("Invalid Input of Xl and Xu")
        return
    xm_old = 0 #random value
    for i in range(20):
        xm = (xl + xr)/2
        Sign = f(xm) * f(xl)
        Ea = abs((xm - xm_old)/xm)*100
        xm_old = xm
        #printing
        if i != 0:
            table.add_row([i+1,xl,xr,xm,Ea])
            #print(i+1,"      ",xm,"     ",Ea)
        else:
            #print(i+1,"      ",xm,"         -",)
            table.add_row([i+1,xl,xr,xm,"--"])
        #updating
        if (Sign == 0):
            break
        elif (Sign < 0):
            xr = xm
        else:
            xl = xm
    print(table)
    print (xm)

ans = bisection(0.001,0.99,0.5,100)
print("Root from Bisection:",ans)
bisection2(0.001,0.99)
