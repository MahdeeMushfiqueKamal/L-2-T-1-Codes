import numpy as np
import matplotlib.pyplot as plt
def f_ab(x):
    return (-11/30)*(x-25)*(x-27)*(x-30) + (43/30)*(x-22)*(x-27)*(x-30) + (-7/5)* (x-22)*(x-25)*(x-30) + (1/3)*(x-22)*(x-25)*(x-27)


def f_bc(x):
    return (-8/7)*(x-31)*(x-35)*(x-37) + (35/24)*((x-30)*(x-35)*(x-37)) + (-3/4)*((x-30)*(x-31)*(x-37)) + (25/84)* (x-30)*(x-31)*(x-35)



#plotting data on matplotlib
fig, ax = plt.subplots()
ax.set_xlabel("X")
ax.set_ylabel("Y")

Xarr = np.linspace(10,30,1000)
lst = list()
for i in Xarr:
    y = f_ab(i)
    lst.append(y)
Yarr = np.array(lst)

ax.plot(Xarr,Yarr, 'b',label= 'f(x)')
ax.scatter(22, 44, color='r')
ax.scatter(25, 43, color='r')
ax.scatter(27, 42, color='r')
ax.scatter(30, 40, color='r')
ax.scatter(28, 41.39999999999999, color='y')

# f_ bc
Xarr = np.linspace(30,40,500)
lst = list()
for i in Xarr:
    y = f_bc(i)
    lst.append(y)
Yarr = np.array(lst)

ax.plot(Xarr,Yarr, 'b',label= 'f(x)')
ax.scatter(31, 35, color='r')
ax.scatter(35, 30, color='r')
ax.scatter(37, 25, color='r')
ax.scatter(32, 32.32142857142858, color='y')

ax.grid(True, which='both')
ax.axhline(y=0, color='k')
ax.axvline(x=0, color='k')
plt.show()



