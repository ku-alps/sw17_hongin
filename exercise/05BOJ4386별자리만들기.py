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

distances = [[getDiff(points[i], points[j]) for j in range(n)] for i in range(n)]
initi = 0
initj = 0
for i in range(n):
	for j in range(n):
		if i == j:
			distances[i][j] = MAXDIST
		if distances[i][j] < MINDIST:
			MINDIST = distances[i][j]
			initi = i
			initj = j
#		print(distances[i][j], end='\t\t')
#	print()

### initialization ###
constellation = [initi, initj]
candidates = [i for i in range(n) if i not in constellation]
#print(constellation)
#print(candidates)
distance = getDiff(points[initi], points[initj])
star = 0
while candidates:
	MINDIST = MAXDIST
	for i in constellation:
		for j in candidates: 
#			print("i : " + str(i) + ", j : " + str(j))
			if (distances[i][j] < MINDIST):
				MINDIST = distances[i][j]
				star = j
	candidates.remove(star)
	constellation.append(star)
	distance += MINDIST
#	print("dist = " + str(distance))

print(distance)
#print(constellation)
