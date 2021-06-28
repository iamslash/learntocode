
// linear traversal
// O(N) O(1)
class Solution {
    fun maxProfit(prices: IntArray): Int {
        var sum = 0
        for (i in 1 until prices.size) {
            val diff = prices[i] - prices[i-1]
            if (diff > 0) {
                sum += diff 
            }
        }
        return sum
    }
}
