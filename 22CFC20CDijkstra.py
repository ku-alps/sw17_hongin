import sys

#def show():
#    for r in range(N):
#        for c in range(N): print(g[r][c], end=' ')
#        print()

N, M = map(int, sys.stdin.readline().split())
g = [[100000 for c in range(N)] for r in range(N)]

for i in range(M):
    ai, bi, gi = map(int, sys.stdin.readline().split())
    g[ai-1][bi-1] = gi
    g[bi-1][ai-1] = gi
#show()

dmin = [100000 for c in range(N)]
for c in range(N):
    dmin[c] = g[0][c]
#print(dmin)
T = set()
T.add(0)
vpre = [1 for c in range(N)]

n = 0
pre = dmin[N-1]
while len(T) < N:
    ming = 100000 
    for v in range(N):
        if v not in T and dmin[v] < ming:
            u = v
            ming = dmin[v]
    if ming == 100000:
        break;
    T.add(u)
    for w in range(N):
        if w not in T:
            pre = dmin[w]
            dmin[w] = min(dmin[w], dmin[u] + g[u][w])
            if pre > dmin[w]:
                vpre[w] = u + 1
    #print(dmin)
#print(vpre)

if dmin[N-1] == 100000:
    print(-1)
else:
    path = []
    path.append(N)
    pre = vpre[N-1]
    while pre != 1:
        path.append(pre)
        pre = vpre[pre-1]
    path.append(1)
    for i in range(len(path)):
        print(path[len(path)-i-1], end = ' ')

