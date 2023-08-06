/* Copyright (C) 2023 by iamslash */

package main

import "fmt"

// 1ms 100.00% 1.9MB 100.00%
// math
// O(1) O(1)
func accountBalanceAfterPurchase(purchaseAmount int) int {
    var amt = purchaseAmount
    var digit = amt % 10
    if digit > 0 {
        amt -= digit
        if digit >= 5 {
            amt += 10
        }
    }
    return 100 - amt
}

func main() {
    fmt.Println("hello world")
}
