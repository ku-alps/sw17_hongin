from sys import stdin
from sys import exit
from collections import deque
N, M, L = map(int, stdin.readline().split())
S = stdin.readline().rstrip();

T = []
for i in range(N):
    T.append(stdin.readline().rstrip())
map(list, T)

D = [[0, -1], [-1, 0], [1, 0], [0, 1]] # direction lurd
Q = deque()
Q.append((0, 0, 0, 0, [(0,0)])) # row, col, depth, char, path
ans = (0, 0, 0, 0, [(0,0)])

def enboard(m, r, c):
    return r in range(len(m)) and c in range(len(m[0]))

while Q:
    vertex = Q.popleft()
    r, c, d, idx, path = vertex
    if idx == len(S) - 1 and ans[2] < d:
        ans = vertex

    for dr, dc in D:
        nr, nc, nd, nidx = r+dr, c+dc, d+1, (idx+1)%len(S)
        if enboard(T, nr, nc) and T[nr][nc] == S[nidx]:
            if (nr, nc) in path:
                print(-1)
                exit(0)
            else:
                vertex = nr, nc, nd, nidx, list(path)
                vertex[4].append((nr, nc))
                Q.append(vertex)

if ans == (0, 0, 0, 0, []):
    print(-1)
else:
    print(ans[2]//len(S)+1)
    print(ans[0]+1, ans[1]+1)
