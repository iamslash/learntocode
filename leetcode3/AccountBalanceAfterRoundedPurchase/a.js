// Copyright (C) 2023 by iamslash

/**
 * @param {number} purchaseAmount
 * @return {number}
 */

// 51ms 100.00% 42.3MB 100.00%
// math
// O(1) O(1)
var accountBalanceAfterPurchase = function(purchaseAmount) {
    var amt = purchaseAmount;
    let digit = purchaseAmount % 10;
    if (digit > 0) {
        amt -= digit;
        if (digit >= 5) {
            amt += 10;
        }
    }
    return 100 - amt;  
};
