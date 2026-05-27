func climbStairs(n int) int {
	dp := make([]int, n+1)
	for i := range n+1 {
		dp[i] = -1
	}
	return climbStairsInternal(n, dp)
}

func climbStairsInternal(n int, dp []int) int {
	if(dp[n] == -1) {
		if (n < 2) {
			dp[n] = 1
		} else {
			dp[n] = climbStairsInternal(n-1, dp) + climbStairsInternal(n-2, dp) 
		}
	}
	return dp[n]
}
