/* Copyright (C) 2022 by iamslash */

package main

import "fmt"

// 0ms 100.00% 2MB 53.98%
// stack
// O(N) O(N)
func isValid(s string) bool {
    stck := make([]rune, 0)
    dict := map[rune]rune{')': '(', ']': '[', '}': '{'}
    for _, c := range s {
        if c == ')' || c == ']' || c == '}' {
            if len(stck) > 0 && stck[len(stck)-1] == dict[c] {
                stck = stck[:len(stck)-1]
            } else {
                return false
            }
        } else {
            stck = append(stck, c)
        }
    }
    return len(stck) == 0
}

func main() {
    fmt.Println("hello world")
}
