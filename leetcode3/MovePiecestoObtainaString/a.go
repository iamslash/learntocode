/* Copyright (C) 2022 by iamslash */

package main

import "fmt"

// 55ms 16.46% 6.6MB 94.04%
// two pointers
// O(N) O(1)
func canChange(s string, t string) bool {
    var i, j, n = 0, 0, len(s)
    for i < n || j < n {
        for i < n && s[i] == '_' {
            i++
        }
        for j < n && t[j] == '_' {
            j++
        }
        if i == n ||
           j == n ||
           s[i] != t[j] ||
           (s[i] == 'L' && i < j) ||
           (s[i] == 'R' && i > j) {
            break
        }
        // fmt.Println(i, j)
        i++
        j++
    }
    return i == n && j == n
}

func main() {
    fmt.Println("hello world")
}
