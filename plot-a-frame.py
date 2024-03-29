import matplotlib.pyplot as plt
import numpy as np
from matplotlib import style
from matplotlib import cm
from matplotlib.backend_bases import MouseButton
import os

style.use('dark_background')

def clicked(event):
    if event.button is MouseButton.LEFT:
        x, y = event.xdata, event.ydata
        print(x,y)
        with open("input.txt", "w+") as file:
            file.write("{}\n{}".format(x,y))
        os.system("./julia_set-cpp")

    if event.button is MouseButton.RIGHT:
        x, y = event.xdata, event.ydata
        print(x,y)
        with open("input_zoom.txt", "w+") as filez:
            filez.write("{}\n{}".format(x,y))
        os.system("./mandelbrot_zoom-cpp")

n = 1000

X = []
Y = []

with open("data.txt", 'r') as file:
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

#plt.savefig("{}".format(time))

#plt.imshow(Y)

plt.imshow(array)
plt.title("Mandelbrot's set")
plt.savefig("render_test.png")
plt.connect('button_press_event', clicked)
plt.show()
