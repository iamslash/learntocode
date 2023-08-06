// Copyright (C) 2023 by iamslash

import java.util.*;

// 0ms 100.00% 39.9MB 50.00%
// math
// O(1) O(1)
class Solution {
    public int accountBalanceAfterPurchase(int purchaseAmount) {
        double amt = purchaseAmount * 0.1;
        return 100 - (int)Math.round(amt) * 10;
    }
}
