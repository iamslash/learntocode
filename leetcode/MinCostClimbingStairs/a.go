/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// // 4ms 87.77% 3.1MB 100.00%
// // dynamic programming
// // O(N^2) O(N)
// func min(a, b int) int {
// 	if a < b {
// 		return a
// 	}
// 	return b
// }
// func solve(costs []int, cache []int, i int) int {
// 	// base
// 	if i >= len(costs) {
// 		return 0
// 	}
// 	// recursion
// 	if cache[i] >= 0 {
// 		return cache[i]
// 	}
// 	cache[i] = costs[i] + min(solve(costs, cache, i+1),
// 		solve(costs, cache, i+2))
// 	return cache[i]
// }
// func minCostClimbingStairs(costs []int) int {
// 	cache := make([]int, 1000)
// 	for i := 0; i < 1000; i++ {
// 		cache[i] = -1
// 	}
// 	return min(solve(costs, cache, 0),
// 		solve(costs, cache, 1))
// }

// // 4ms 87.77% 2.9MB 100.00%
// // dynamic programming
// // O(N) O(1)
// func minCostClimbingStairs(cost []int) int {
// 	a, b, minCost := 0, 0, 0
// 	for i := 2; i <= len(cost); i++ {
// 		if a+cost[i-1] > b+cost[i-2] {
// 			minCost = b + cost[i-2]
// 		} else {
// 			minCost = a + cost[i-1]
// 		}
// 		a, b = minCost, a
// 	}
// 	return minCost
// }

// 4ms 87.77% 2.9MB 100.00%
// dynamic programming
// O(N) O(1)
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func minCostClimbingStairs(cost []int) int {
	for i := 2; i < len(cost); i++ {
		cost[i] += min(cost[i-1], cost[i-2])
	}
	return min(cost[len(cost)-1], cost[len(cost)-2])
}

func main() {
	fmt.Println("hello world")
}
