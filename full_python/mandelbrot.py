import matplotlib.pyplot as plt
import numpy as np
import cmath

print("format for complex numbers is : RE(z) + IM(z)j \n")

Z_list = []
J_c = []
J_c_x = []
J_c_y = []
threshold = 80

re_c = np.linspace(-2, 2, 5000)
im_c = np.linspace(-2, 2, 5000)

def z_n(z, c):
    Z = z*z + c
    return(Z)

for y in range(len(im_c)):
    J_c_x = []
    for x in range(len(re_c)):
        c = re_c[x] + im_c[y]*1j
        z = z_n(0, c)

        for i in range(threshold):
            z = z_n(z, c)

        if cmath.isfinite(z):
            J_c_x.append(1)
        else:
            J_c_x.append(0)
    J_c_y.append(J_c_x)
    print(y, " / ", len(im_c))

plt.imshow(J_c_y)
plt.show()
