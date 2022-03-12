/* Copyright (C) 2022 by iamslash */

package main

import "fmt"

// 0 0 1
// 0 1 0
// 1 0 0

// 55ms 22.22% 8.7MB 88.89%
// hash table
// Move: O(1) O(N)
func abs(a int) int {
    if a < 0 {
        return -a
    }
    return a
}

type TicTacToe struct {
    rows []int
    cols []int
    ldiag int
    rdiag int
}

func Constructor(n int) TicTacToe {
    return TicTacToe{
        rows: make([]int, n),
        cols: make([]int, n),
        ldiag: 0,
        rdiag: 0,
    }
}
func (t *TicTacToe) Move(row int, col int, player int) int {
    n := len(t.rows)
    cell := 1
    if player == 2 {
        cell = -1
    }
    t.rows[row] += cell
    t.cols[col] += cell
    if row == col {
        t.ldiag += cell
    }
    if row == (n - col - 1) {
        t.rdiag += cell
    }
    if abs(t.rows[row]) == n ||
        abs(t.cols[col]) == n ||
        abs(t.ldiag) == n ||
        abs(t.rdiag) == n {
        return player
    }
    return 0
}

func main() {
    fmt.Println("hello world")
}
