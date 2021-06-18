import math
u = 2000
m0 = 140000
q = 2100

def f(t):
    return u * math.log(m0 / (m0 - q*t) ) - 9.8*t

def findArea(a,b,sub_intervals):
    n = sub_intervals*2

    h = (b-a)/n
    area = f(a) + f(b)

    for i in range(1,n,2):
        area += 4* f(a + i*h)
    
    for i in range(2,n,2):
        area += 2* f(a + i*h)

    area *= h
    area/= 3
    return area

n = int(input("1. Enter the number of sub-intervals:   "))
t1 = 8
t2 = 30

print(findArea(t1,t2,n))