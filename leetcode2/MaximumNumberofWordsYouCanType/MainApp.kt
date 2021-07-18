/* Copyright (C) 2021 by iamslash */

// 176ms 100.00% 36.4MB 100.00%
// hash map
// O(N) O(1)
class Solution {
    fun broken(word: String, brokenIdxs: IntArray): Boolean {
        for (c in word) {
            if (brokenIdxs[c-'a'] > 0) {
                return true
            }
        }
        return false
    }
    fun canBeTypedWords(text: String, brokenLetters: String): Int {
        val brokenIdxs = IntArray(26)
        for (c in brokenLetters) {
            brokenIdxs[c-'a'] = 1
        }
        val textArr = text.split(" ")
        return textArr.filter({ broken(it, brokenIdxs) == false })
            .count()
    }
}

fun main() {
    println("Hello World")
}
