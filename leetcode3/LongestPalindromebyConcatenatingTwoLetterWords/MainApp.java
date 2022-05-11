// Copyright (C) 2022 by iamslash

import java.util.*;

// words: cc ll xx
// 

// 17ms 95.58% 96.9MB 67.57%
// hash map
// O(N) O(1)
class Solution {
    public int longestPalindrome(String[] words) {
        int cnts[][] = new int[26][26];
        int ans = 0;
        for (String word : words) {
            int a = word.charAt(0) - 'a', b = word.charAt(1) - 'a';
            if (cnts[b][a] > 0) {
                ans += 4;
                cnts[b][a]--;
            } else {
                cnts[a][b]++;
            }
        }
        for (int i = 0; i < 26; ++i) {
            if (cnts[i][i] > 0) {
                ans += 2;
                break;
            }
        }
        return ans;
    }
}
