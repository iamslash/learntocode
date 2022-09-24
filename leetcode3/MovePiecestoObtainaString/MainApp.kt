/* Copyright (C) 2022 by iamslash */

// 503ms 100.00% 66.4MB 75.00%
// two pointers
// O(N) O(1)
class Solution {
    fun canChange(s: String, t: String): Boolean {
        var i = 0
        var j = 0
        val n = s.length
        while (i < n || j < n) {
            while (i < n && s.get(i) == '_') {
                i++
            }
            while (j < n && t.get(j) == '_') {
                j++;
            }
            if (i == n ||
                j == n ||
                s.get(i) != t.get(j) ||
                (s.get(i) == 'L' && i < j) ||
                (s.get(i) == 'R' && i > j)) {
                break
            }
            i++
            j++
        }
        return i == n && j == n
    }
}
