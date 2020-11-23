/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// Check `(x, y)` minimum distance from ciecle to rectangle
// less than square of radius `r`.
// x^2 + y^2 <= r^2
// If x1 * x2 < 0, x should be 0.
// If y1 * y2 < 0, y should be 0.

// 0ms 100.00% 2MB 100.00%
// math
// O(1) O(1)
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func checkOverlap(r, xc, yc, x1, y1, x2, y2 int) bool {
	//
	x1 -= xc
	x2 -= xc
	y1 -= yc
	y2 -= yc
	minXSquare := 0
	if x1*x2 > 0 {
		minXSquare = min(x1*x1, x2*x2)
	}
	minYSquare := 0
	if y1*y2 > 0 {
		minYSquare = min(y1*y1, y2*y2)
	}
	return minXSquare+minYSquare <= r*r
}

func main() {
	fmt.Println("hello world")
}
