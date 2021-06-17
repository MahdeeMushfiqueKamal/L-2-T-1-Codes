import math
from prettytable import PrettyTable 

u = 2000
m0 = 140000
q = 2100

def f(t):
    return u * math.log(m0 / (m0 - q*t) ) - 9.8*t

def findArea(low_limit,high_limit,n):
    area = 0
    h = (high_limit-low_limit)/n
    a = low_limit

    for i in range(n):
        trap = 0.5* h * (f(a+h) + f(a))
        area += trap
        a += h
    return area


n = int(input("1. Enter the number of sub-intervals:   "))
t1 = 8
t2 = 30

print(findArea(8,30,n))

print("Part 2")
table = PrettyTable(["Sub-intervals","Calculated value","Abs Relative Appx Error"])


area_old = findArea(8,30,1)
table.add_row([1, area_old, '-'])
for i in range(2,6):
    area_new = findArea(8,30,i)
    appxRelError = 100*abs(area_new- area_old)/area_new
    table.add_row([i, area_new, appxRelError])
    area_old = area_new

print(table)


