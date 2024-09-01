// Copyright (C) 2024 by iamslash

import java.util.*;

// 16ms 86.61% 45.2MB 62.29%
// recursive dynamic programming
// O(N * 2^M) O(2^M + N)
// N: stickers number
// M: target length
class Solution {

    private int dfs(Map<String, Integer> C, int[][] stickerFreqs, String target) {
        // base
        if (target.isEmpty()) {
            return 0;
        }
        
        // memo
        if (C.containsKey(target)) {
            return C.get(target);
        }
        
        // recursion
        int[] targetFreq = new int[26];
        for (char c : target.toCharArray()) {
            targetFreq[c -'a']++;
        }
        int minCnt = Integer.MAX_VALUE;
        for (int[] stickerFreq : stickerFreqs) {
            // Inf loops without this block 
            if (stickerFreq[target.charAt(0) - 'a'] == 0) {
                continue;
            }

            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < 26; ++i) {
                if (targetFreq[i] > 0) {
                    int bnd = Math.max(0, targetFreq[i] - stickerFreq[i]);
                    for (int j = 0; j < bnd; ++j) {
                        sb.append((char)(i + 'a'));
                    }
                }
            }

            int cnt = dfs(C, stickerFreqs, sb.toString());
            if (cnt != -1) {
                minCnt = Math.min(minCnt, cnt + 1);
            }
        }

        C.put(target, minCnt == Integer.MAX_VALUE ? -1 : minCnt);
        return C.get(target);
    }

    
    public int minStickers(String[] stickers, String target) {
        int n = stickers.length;
        Map<String, Integer> C = new HashMap<>();
        int[][] freqs = new int[n][26];

        for (int i = 0; i < n; ++i) {
            for (char c : stickers[i].toCharArray()) {
                freqs[i][c - 'a']++;
            }
        }

        C.put("", 0);
        return dfs(C, freqs, target);
    }
}
