#imports
import math
import numpy as np
import matplotlib.pyplot as plt

#read data
X = []
Y = []
for line in open('data.txt').readlines():
    line = line.split(' ')
    X.append(float(line[0]))
    Y.append(float(line[1]))
noOfPoints = len(X)





#plotting data on matplotlib
fig, ax = plt.subplots()
ax.set_xlabel("X")
ax.set_ylabel("Y")

for i in range(noOfPoints):
    ax.scatter(X[i],Y[i],color = 'r',marker = 'x')

ax.grid(True, which='both')
ax.axhline(y=0, color='k')
ax.axvline(x=0, color='k')
plt.show()