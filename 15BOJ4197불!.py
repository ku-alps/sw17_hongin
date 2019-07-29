R,C = map(int, input().split())

class Map():
    global R
    global C
    arr = [['X']*C]*R

arr = [['X']*C]*R
for r in range(R):
	line = input()
	for c in range(C):
		arr[r][c] = line[c]

