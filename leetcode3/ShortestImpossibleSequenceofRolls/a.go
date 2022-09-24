/* Copyright (C) 2022 by iamslash */

package main

import "fmt"

// 157ms 78.43% 8.5MB 98.04%
// hash set
// O(N) O(K)
func shortestSequence(rolls []int, k int) int {
    var ans = 1
    var diceSet = make(map[int]struct{})
    for _, e := range rolls {
        diceSet[e] = struct{}{}
        if len(diceSet) == k {
            diceSet = make(map[int]struct{})
            ans++
        }
    }
    return ans
}

func main() {
    fmt.Println("hello world")
}
