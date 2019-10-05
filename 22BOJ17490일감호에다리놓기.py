from sys import stdin, exit

N, M, K = map(int, stdin.readline().split())
S = []
S.extend(map(int, stdin.readline().split()))
C = []

if M == 0 or M == 1:
    print("YES")
    exit(0)

for i in range(M):
    start, end = [int(i)  for i in stdin.readline().split()]
    if max(start, end) == N and min(start, end) == 1:
        C.append(max(start, end))
    else :
        C.append(min(start, end))
    #print(C)

C.sort()
#print("###############")

#print(C)

B=[]
start, end = 0, 0
if C[-1] == len(S):
    start, end = 0, C[0]
    B.append(S[start:end])
else:
    start, end = C[-1], C[0]
    first = S[start:]
    first.extend(S[0:end])
    B.append(first)
J = []
J.append(min(B[0]))

i = 1
while i < len(C):
    start, end = end, C[i]
    #print("loop", i, start, end, S[start:end])
    #B.append(S[start:end])
    #print(B)
    #J.append(min(B[i]))
    i+=1
    #print(J)
#print(B)
#print(J)
#print(sum(J), 'vs', K)
if sum(J) <= K:
    print("YES")
else:
    print("NO")
