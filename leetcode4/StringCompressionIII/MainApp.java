// Copyright (C) 2024 by iamslash

import java.util.*;

// 26ms 39.30% 45.6MB 81.78%
// two pointers
// O(N) O(1)
class Solution {
    public String compressedString(String word) {
        int n = word.length(), cnt = 0, i = 0, j = 0;
        StringBuilder ans = new StringBuilder();

        while (i < n) {
            cnt = 0;
            while (j < n && word.charAt(i) == word.charAt(j) && cnt < 9) {
                j++;
                cnt++;
            }
            ans.append(String.valueOf(cnt));
            ans.append(word.charAt(i));
            i = j;
        }

        return ans.toString();
    }
}
