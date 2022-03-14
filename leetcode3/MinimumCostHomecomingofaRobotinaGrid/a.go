/* Copyright (C) 2022 by iamslash */

package main

import "fmt"

// 246ms 71.43% 10.4MB 14.29%
// move one unit
// O(N) O(1)
func abs(a int) int {
    if a < 0 {
        return -a
    }
    return a
}
func minCost(startPos []int, homePos []int, rowCosts []int, colCosts []int) int {
    cost, y, x, z, w := 0, startPos[0], startPos[1], homePos[0], homePos[1]
    for y != z {
        y += (z - y) / abs(z - y)
        cost += rowCosts[y]
    }
    for x != w {
        x += (w - x) / abs(w - x)
        cost += colCosts[x]
    }
    return cost
}

func main() {
    fmt.Println("hello world")
}
