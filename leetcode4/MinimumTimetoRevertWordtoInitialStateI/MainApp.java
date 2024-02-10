// Copyright (C) 2024 by iamslash

import java.util.*;

//    k: 3
//             i
// word: abacaba
//       j

//    k: 4
//              i
// word: abacaba
//          j
//           abacaba

//    k: 4
//           i
// word: abccab
//       j
//           ab
//

// Idea: kmp
//
// If we remove first k characters,
// We can add any characters.
// Just compare remained characters
// with intial characters.

// kmp
// O(N) O(1)
// 1ms 99.73% 41.2MB 99.82%
class Solution {
    private boolean equal(String word, int i) {
        int n = word.length();
        for (int j = 0; j + i < n; ++j) {
            if (word.charAt(j) != word.charAt(i + j)) {
                return false;
            }
        }
        return true;
    }
    public int minimumTimeToInitialState(String word, int k) {
        int cnt = 1, n = word.length();
        for (int i = k; i < n; i += k) {
            if (equal(word, i)) {
                return cnt;
            }
            cnt++;
        }
        return cnt;
    }
}

