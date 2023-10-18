def countWaysToCompleteGame(N, P, X):
    # Initialize a 2D array to store the number of ways for each player and each move
    dp = [[0] * (N + 1) for _ in range(X + 1)]

    # For each move (0 to X) and each player (1 to N), set the base case
    for i in range(1, N + 1):
        dp[0][i] = 1

    # Fill the dp array using dynamic programming
    for move in range(1, X + 1):
        for player in range(1, N + 1):
            dp[move][player] = 0
            for other_player in range(1, N + 1):
                if player != other_player and (player % other_player == 0 or other_player % player == 0):
                    dp[move][player] += dp[move - 1][other_player]

    return dp[X][P]


# Example 1
print(countWaysToCompleteGame(3, 2, 2))  # Output: 1

# Example 2
print(countWaysToCompleteGame(3, 2, 4))  # Output: 3
