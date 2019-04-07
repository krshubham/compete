def answer(n):
    dp = [[0 for i in range(n + 1)] for j in range(n + 1)]
    dp[0][0] = 1
    for h in range(1, n + 1):
        for l in range(n + 1):
            dp[h][l] = dp[h - 1][l]
            if l >= h:
                dp[h][l] += dp[h - 1][l - h]
    return dp[n][n]-1
