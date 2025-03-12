// Copyright (C) 2025 by iamslash

import java.util.*;

//      k: 3
//         i
// colors: 0 1 0 1 0 
//                   0 1 0 1 0
//                   j
//         - - -
//           - - -
//             - - -
//               - - -
//                 - - -

// Time Limit Exceeded
// brute force
// O(NK) O(1)
class Solution {
    public int numberOfAlternatingGroups(int[] colors, int k) {
        int n = colors.length, cnt = 0;

        for (int i = 0; i < n; ++i) {

            int j = i + 1, prev = colors[i];
            while (j < i + k && prev != colors[j % n]) {
                prev = colors[j % n];
                j++;
            }
            if (j == i + k) {
                cnt++;
            } else {
                i = j - 1;
            }
        }

        return cnt;
    }
}

// Idea: sliding window
//
//      k: 3
//                   l
// colors: 0 1 0 1 0 
//                   0 1 0 1 0
//                       r
//         - - -
//           - - -
//             - - -
//               - - -
//                 - - -
//
// 5ms 48.47% 63.44MB 16.22%
// sliding window
// O(N) O(1)
class Solution {
    public int numberOfAlternatingGroups(int[] colors, int k) {
        int n = colors.length, cnt = 0, left = 0;

        for (int right = 0; right < n + k - 1; right++) {
            if (right > 0 && colors[(right - 1) % n] == colors[right % n]) {
                left = right;
            }

            if (right - left + 1 >= k) {
                cnt++;
            }
        }

        return cnt;
    }
}
