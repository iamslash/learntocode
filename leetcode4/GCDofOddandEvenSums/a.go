/* Copyright (C) 2025 by iamslash */

package main

import "fmt"

// 0ms 100.00% 4.00MB 100.00%
// math
// O(1) O(1)
func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}
func gcd(a, b int) int {
    // base
    if b == 0 {
        return abs(a)
    }
    // recursion
    return gcd(b, a % b)
}
func gcdOfOddEvenSums(n int) int {
    nn := n + n
    sum := nn * (nn + 1) / 2
    sumOdd := (sum - n) / 2
    sumEvn := sumOdd + n
    
    return gcd(sumEvn, sumOdd)
}

func main() {
    fmt.Println("hello world")

}
