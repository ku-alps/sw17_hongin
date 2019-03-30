#!/usr/bin/python3

line = input().split()
N = int(line[0])
K = int(line[1])
#A = [1, 5, 10, 50, 100, 500, 1000, 5000, 10000, 50000]
A = []
for i in range(N):
	A.append(int(input()))

answer = 0
for i in range(N-1, -1, -1):
	answer += K//A[i]
	K = K % A[i]
print(answer)
