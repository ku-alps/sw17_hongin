T = int(input())

for t in range(T):
    score = map(int, input().split())
    good = mean(score[1:])
