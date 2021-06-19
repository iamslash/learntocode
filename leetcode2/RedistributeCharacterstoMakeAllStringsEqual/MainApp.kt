// modulo
// O(N) O(1)
// 168ms 100.00% 35.6MB 96.15%
class Solution {
    fun makeEqual(words: Array<String>): Boolean {
        val wordCnt = words.size
        var charCnt = 0
        val freqs = IntArray(26)
        for (word in words) {
            for (c in word) {
                charCnt++
                freqs[c-'a']++
            }
        }
        if (charCnt % wordCnt != 0) {
            return false
        }
        for (i in 0..25) {
            if (freqs[i] % wordCnt != 0) {
                return false
            }
        }
        return true
    }
}

fun main() {
}  
