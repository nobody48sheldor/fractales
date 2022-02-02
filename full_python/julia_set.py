import matplotlib.pyplot as plt
import numpy as np
import cmath

print("format for complex numbers is : RE(z) + IM(z)j \n")

c = complex(input("c = "))
Z_list = []
J_c = []
J_c_x = []
J_c_y = []
threshold = 80

re_e = np.linspace(-2, 2, 5000)
im_e = np.linspace(-2, 2, 5000)

def z_n(z, c):
    Z = z*z + c
    return(Z)

for y in range(len(im_e)):
    J_c_x = []
    for x in range(len(re_e)):
        e = re_e[x] + im_e[y]*1j
        z = z_n(e, c)

        for i in range(threshold):
            z = z_n(z, c)

        if cmath.isfinite(z):
            J_c_x.append(1)
        else:
            J_c_x.append(0)
    J_c_y.append(J_c_x)
    print(y, " / ", len(im_e))

plt.imshow(J_c_y)
plt.show()
