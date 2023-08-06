/* Copyright (C) 2023 by iamslash */

import java.util.*;

// 120ms 100.00% 32.4MB 100.00%
// math
// O(1) O(1)
class Solution {
    fun accountBalanceAfterPurchase(purchaseAmount: Int): Int {
        var amt = purchaseAmount;
        var digit = amt % 10;
        if (digit > 0) {
            amt -= digit;
            if (digit >= 5) {
                amt += 10;
            }
        }
        return 100 - amt;
    }
}

fun main() {
    println("Hello World")
}
