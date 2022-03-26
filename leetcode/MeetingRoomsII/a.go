/* Copyright (C) 2022 by iamslash */

package main

import (
    "fmt"
    "sort"
)

//        i
// begs:  0 5  15
// ends: 10 20 30
//        j

// 11ms 64.17% 4.6MB 63.61%
// two pointers, sort
// O(NlgN) O(N)
func minMeetingRooms(intervals [][]int) int {
    n, ans := len(intervals), 0
    begs, ends := make([]int, n), make([]int, n)
    for i := 0; i < n; i++ {
        begs[i], ends[i] = intervals[i][0], intervals[i][1]
    }
    sort.Ints(begs)
    sort.Ints(ends)
    for i, j := 0, 0; i < n; i++ {
        if begs[i] < ends[j] {
            ans++
        } else {
            j++
        }
    }
    return ans
}

func main() {
    fmt.Println("hello world")
}
