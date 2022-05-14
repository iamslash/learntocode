// Copyright (C) 2022 by iamslash

import java.util.*;

//   k: 2
// num: 240

// 5ms 50.00% 39.6MB 100.00%
// brute force
// O(N) O(1)
class Solution {
    public int divisorSubstrings(int num, int k) {
        String numStr = Integer.toString(num), wndStr = "";
        int n = numStr.length(), cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (i >= k) {
                wndStr = String.format("%s%c", wndStr.substring(1), numStr.charAt(i));
            } else {
                wndStr = String.format("%s%c", wndStr, numStr.charAt(i));
            }
            if (i >= k - 1) {
                int wndNum = Integer.valueOf(wndStr);
                if (wndNum != 0 && num % wndNum == 0) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
}

// 1ms 100.00% 41.6MB 100.00%
// brute force
// O(N) O(1)
class Solution {
    public int divisorSubstrings(int num, int k) {
        String numStr = Integer.toString(num);
        int cnt = 0, wndNum = 0, n = numStr.length();
        for (int i = 0, j = k; j <= n; ++i, j++) {
            wndNum = Integer.valueOf(numStr.substring(i, j));
            if (wndNum != 0 && num % wndNum == 0) {
                cnt++;
            }
        }
        return cnt;
    }
}
