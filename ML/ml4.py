
import numpy as np
import matplotlib.pyplot as plt
import math


def dist(p1 , p2):
	d = math.sqrt( (p1[0] - p2[0])**2 + (p1[1] - p2[1])**2 )
	return d


def calc_cent(cl):
	x = 0
	y = 0
	for i in range(len(cl)):
		x = x + cl[i][0]
		y = y + cl[i][1]
	x = x / len(cl)
	y = y / len(cl)
	p = [x,y]
	return p



points= [ 
		[0.1,0.6] , [0.15,0.71] , [0.08,0.9] , [0.16,0.85] , [0.2,0.3] , [0.25,0.5] , [0.24,0.1] , [0.3,0.2]
	]
k = 2

cl1 = [points[0]]
cl2 = [points[7]]

cent1 = points[0]
cent2 = points[7]



for i in range(1,7):
	d1 = dist(cent1 , points[i])
	d2 = dist(cent2 , points[i])
	if d1>d2 :
		cl2.append(points[i])
		cent2 = calc_cent(cl2)
	else:
		cl1.append(points[i])
		cent1 = calc_cent(cl1)


x1 = []
y1 = []
for i in range(len(cl1)):
	x1.append(cl1[i][0]) 
	y1.append(cl1[i][1])

x2 = []
y2 = []

for i in range(len(cl2)):
	x2.append(cl2[i][0])
	y2.append(cl2[i][1])

p = points[5]

b = False

for i in range(len(cl1)-1):
	if p == cl1[i] :
		b = True
		break
		
if b == True :
	print("Point 6 is in Cluster : 1")
else : 
	print("Point 6 is in Cluster : 2")

print("Population of Cluster 2 is : " , len(cl2) )

print("Value of centroid 1 : m1 : " , cent1)
print("Value of centroid 2 : m2 : " , cent2)

print("\n")
print("Cluster 1 : " , cl1)

print("\n")
print("Cluster 2 : " , cl2)

 	

plt.scatter(x1,y1 , c='blue')
plt.scatter(x2,y2 , c='red')
plt.scatter(cent1[0] , cent1[1] , c='green')
plt.scatter(cent2[0] , cent2[1] , c='green')
plt.xlabel('x')
plt.ylabel('y')
plt.show()


		
