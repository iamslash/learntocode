// Copyright (C) 2024 by iamslash

import java.util.*;

//               i
//      s: a a a a
//               j
//
// cntMap: a aa aaa aaaa
//         4  3   2    1

// 63ms 30.37% 45MB 58.66%
// hash map
// O(N^2) O(N)
class Solution {
    public int maximumLength(String s) {
        char[] chrs = s.toCharArray();
        int ans = -1, n = chrs.length;
        Map<String, Integer> cntMap = new HashMap<>();

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                String cur = s.substring(i, j + 1);
                cntMap.put(cur, cntMap.getOrDefault(cur, 0) + 1);
            }
        }

        for (String key : cntMap.keySet()) {
            if (cntMap.get(key) >= 3) {
                int keyLen = key.length(), chrCnt = 0;
                for (int i = 0; i < keyLen; ++i) {
                    if (key.charAt(i) == key.charAt(0)) {
                        chrCnt++;
                    } else {
                        break;
                    }
                }
                if (chrCnt == keyLen) {
                    ans = Math.max(ans, keyLen);
                }
            }
        }
       
        return ans;
    }
}

//    i
// s: a a a a
//            j
//            k
//    x



// 2ms 99.91% 44.5MB 74.86%
// sliding window
// O(N) O(N)
// difficult
class Solution {
    public int maximumLength(String s) {
        int sLen = s.length();
        char[] chrs = s.toCharArray();
        int[][] cntMap = new int[26][sLen];
        int ans = -1, n = chrs.length, i = 0;
        while (i < n) {
            int j = i;

            while (j < n && chrs[j] == chrs[i]) {
                j++;
            }

            int idx = 0;
            for (int k = j - i; k > 0; k--, idx++) {
                cntMap[chrs[i] - 'a'][idx] += k;
                if (cntMap[chrs[i] - 'a'][idx] > 2)
                    ans = Math.max(ans, idx + 1);
            }

            i = j; //jump to first different 
        }
        return ans;
    }     
}
