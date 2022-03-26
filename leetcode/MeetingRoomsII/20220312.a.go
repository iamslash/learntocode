/* Copyright (C) 2022 by iamslash */

package main

import (
    "fmt"
    "sort"
)

// intervals: 0,30 5,10 15,20
//                     i
//      begs:  0  5 15
//      ends: 10 20 30
//                j
//       cnt:  2

// 10ms 67.78% 4.6MB 69.45%
// two pointers, sort
// O(N) O(N)
func minMeetingRooms(intervals [][]int) int {
    n, cnt, j := len(intervals), 0, 0
    begs := make([]int, n)
    ends := make([]int, n)
    for i := 0; i < n; i++ {
        begs[i] = intervals[i][0]
        ends[i] = intervals[i][1]
    }
    sort.Ints(begs)
    sort.Ints(ends)
    // fmt.Println(begs)
    // fmt.Println(ends)
    for i := 0; i < n; i++ {
        if begs[i] < ends[j] {
            cnt++
        } else {
            j++
        }
    }
    return cnt;
}

func main() {
    fmt.Println("hello world")
}
