import matplotlib.pyplot as plt
import numpy as np
from matplotlib import style
from matplotlib import cm
from mpl_toolkits.mplot3d import axes3d
import time

style.use('dark_background')

n = 500

X = []
Y = []

with open("data_julia.txt", 'r') as file:
    data = file.readlines()

data = data[0].split("/",n*n)

for i in range(len(data)-1):
    data[i] = float(data[i])

for y in range(n):
    X = []
    for x in range(n):
        X.append(data[int(y*n + x)])
    Y.append(X)

array = np.array(Y)

plt.imshow(array)
plt.title("julia's set")
plt.show()
