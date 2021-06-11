import numpy as np
import matplotlib.pyplot as plt

X = np.array([10,100,1000,10000,100000,1000000])
merge_rnd = np.array([0,0,400,3500,24800,221200])
quick_rnd = np.array([0,0,0,1167,13800,171800])

plt.plot(X, merge_rnd, 'r', label = 'merge_rnd')
plt.plot(X,quick_rnd ,'k', label = 'quick_rnd')

merge_asc = np.array([])
quick_asc = np.array([])

merge_dsc = np.array([])
quick_dsc = np.array([])


plt.grid(True, which='both')
plt.axhline(y=0, color='blue')
plt.axvline(x=0, color='blue')

# Labeling axis
plt.xlabel('x - axis')
plt.ylabel('y - axis')

plt.show()