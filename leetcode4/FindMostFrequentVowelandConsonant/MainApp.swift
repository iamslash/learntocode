/* Copyright (C) 2025 by iamslash */

import Foundation

// 2ms 63.33% 19.84MB 63.33%
// brute force
// O(N) O(1)
class Solution {
    func maxFreqSum(_ s: String) -> Int {
        var maxVowelCnt = 0
        var maxConsonantCnt = 0
        var charCnts = Array<Int>(repeating: 0, count: 26)
        let vowels: Set<Character> = ["a", "e", "i", "o", "u"]

        for c in s {
            if let asciiC = c.asciiValue, let asciiA = Character("a").asciiValue {
                
                let idx = Int(asciiC - asciiA)
                charCnts[idx] += 1

                if vowels.contains(c) {
                    if charCnts[idx] > maxVowelCnt {
                        maxVowelCnt = charCnts[idx]
                    }
                } else {
                    if charCnts[idx] > maxConsonantCnt {
                        maxConsonantCnt = charCnts[idx]
                    }
                }
            }
        }

        return maxVowelCnt + maxConsonantCnt
    }
}
