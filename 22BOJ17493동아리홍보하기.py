import sys

def show():
    for r in range(N):
        for c in range(N):
            print(mat[r][c], end='')
        print()

N, M = map(int, sys.stdin.readline().split())
mat = [[0 for c in range(N)] for r in range(N)]

for m in range(M):
    start, end = [int(word)-1 for word in sys.stdin.readline().split()]
    mat[start][end] = 1
    mat[end][start] = 1

show()

