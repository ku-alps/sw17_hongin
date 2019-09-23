import heapq

def dist(x1, y1, z1, x2, y2, z2):
    return min(min(abs(x1-x2), abs(y1-y2)), abs(z1-z2))

def dist_v(v1, v2):
    return dist(v1[0], v1[1], v1[2], v2[0], v2[1], v2[2])


n = int(input())
star = []
for i in range(n): 
    x, y, z = map(int, input().split())
    star.append((x, y, z))

first = star.pop()
T = set(first)
Q = []
for v in star: 
    heapq.heappush(Q, (dist_v(v, first), v))

ans = 0
while Q: 
    (d, v) = heapq.heappop(Q)
    T.add(v)
    
    ans += d

    QQ = []
    for i, q in enumerate(Q):
        heapq.heappush(QQ, (min(q[0], dist_v(v, q[1])), q[1]))
    Q = QQ
        
print(ans)

