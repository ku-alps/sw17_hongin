#!/usr/bin/python
import math

MAXDIST = 1415
MINDIST = 1415
def getDiff(apoint, otherpoint):
	dist = math.sqrt((apoint[0]-otherpoint[0])**2 + (apoint[1]-otherpoint[1])**2)
	return dist;

n = int(input())

points = []
for i in range(n):
	point = [int(value) for value in input().split() if value.isdigit()]
	points.append(point)

distances = []
for i in range(n):
	row = []
	for j in range(n):
		if (i == j ):
			temp = MAXDIST
		else:
			temp = getDiff(points[i], points[j])
			row.append(temp)
		print(temp, end = '\t\t')
	distances.extend(row)
	print()

### initialization ###
candidates = [int(i) for i in range(n)]
for i in candidates:
	print(i)

constellation = []
mini = 0
minj = 0
for i in range(n):
	for j in range(n):
	if (distances[i][j] < MINDIST):
			MINDIST = distances[i][j]
			mini = i
			minj = j

constellation.append([mini, minj]	)
distances[mini][minj] = MAXDIST
distnaces[mini][minj] = MAXDIST
	
print(constellation[0])
