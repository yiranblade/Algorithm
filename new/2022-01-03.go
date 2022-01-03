package main

func main() {
	result := fibDp(20)
	println(result)
}
// 备忘录解发
func fib(N int) int {
	if N < 1 {
		return 0
	}
	memo := make([]int, N+1)
	helper(memo, N)
	return memo[N]
}

func helper(memo []int, n int) int {
	if n == 1 || n == 2 {
		return 1
	}
	if memo[n] != 0 {
		return memo[n]
	}
	memo[n] = helper(memo, n-1) + helper(memo, n-2)
	return memo[n]
}

//dp
func fibDp(N int) int {
	dp := make([]int, N+1)
	dp[1] = 1
	dp[2] = 1
	for i := 3; i <= N; i++ {
		dp[i] = dp[i-1] + dp[i-2]
	}
	return dp[N]
}