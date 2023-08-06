
// 0ms 100.00% 13.9MB 100.00%
// math
// O(1) O(1)
class Solution {
    func accountBalanceAfterPurchase(_ purchaseAmount: Int) -> Int {
        var amt = purchaseAmount;
        let dgt = amt % 10;
        if (dgt > 0) {
            amt -= dgt;
            if (dgt >= 5) {
                amt += 10;
            }
        }
        return 100 - amt;
    }
}
