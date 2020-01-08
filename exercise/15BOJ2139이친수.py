n = int(input())
dp = [[0 for c in range(2)] for r in range(n)]

dp[0][0] = 0
dp[0][1] = 1
for i in range(1, n): # 0 ~ n-1
#    print(i)
    dp[i][0] = dp[i-1][0] + dp[i-1][1]
    dp[i][1] = dp[i-1][0]
#    print(dp[i][0], " ", dp[i][1])
#print(dp)
ans = dp[n-1][0] + dp[n-1][1]
print(ans)
