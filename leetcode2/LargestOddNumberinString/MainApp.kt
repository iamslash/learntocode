
// 204ms 100.00% 40.4MB 100.00%
// linear traversal
// O(N) O(1)
class Solution {
    fun largestOddNumber(s: String): String {
        var pos = s.length - 1
        while (pos >= 0 &&
               (s.get(pos)-'0') % 2 == 0) {
            pos--;
        }
        return s.substring(0, pos+1)
    }
}
