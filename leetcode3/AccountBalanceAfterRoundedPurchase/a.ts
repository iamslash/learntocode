// Copyright (C) 2023 by iamslash

// 47ms 100.00% 42.4MB 100.00%
// math
// O(1) O(1)
function accountBalanceAfterPurchase(purchaseAmount: number): number {
    var amt = purchaseAmount;
    let dgt = purchaseAmount % 10;
    if (dgt > 0) {
        amt -= dgt;
        if (dgt >= 5) {
            amt += 10;
        }
    }
    return 100 - amt;
};
