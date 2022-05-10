import numpy as np
import matplotlib.pyplot as plt

x = np.array([10,9,2,15,10,16,11,16])
y = np.array([95,80,10,50,45,98,38,93])

n = np.size(x)

mx = np.mean(x)
my = np.mean(y)

# calculating cross-deviation and deviation about x

xy = np.sum(y*x) - n*my*mx
xx = np.sum(x*x) - n*mx*mx

b1 = xy / xx
b0 = my - b1*mx

print("Coeffiecients : " )
print("\n")
print("b0 : ")
print(b0)
print("b1 : ")
print(b1)

y_pred = b0 + b1*x


plt.scatter(x, y)

plt.plot(x,y_pred)

plt.xlabel('x')
plt.ylabel('y')

plt.show()



