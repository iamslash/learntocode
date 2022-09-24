/* Copyright (C) 2022 by iamslash */

// 770ms 64.29% 90.6MB 21.43%
// hash set
// O(N) O(K)
class Solution {
    fun shortestSequence(rolls: IntArray, k: Int): Int {
        var ans = 1
        val diceSet = mutableSetOf<Int>()
        for (roll in rolls) {
            diceSet.add(roll)
            if (diceSet.size == k) {
                diceSet.clear();
                ans++
            }
        }
        return ans
    }
}
