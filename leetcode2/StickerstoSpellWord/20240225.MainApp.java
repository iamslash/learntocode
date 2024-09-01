// Copyright (C) 2024 by iamslash

import java.util.*;


// Idea: dfs
// 
//                        i
//   stickers: with example science
//     target: thehat
//
// stickeFreq: i h t w
//             1 1 1 1
//             a e l m p x
//             1 2 1 1 1 1
//             c e i n s
//             2 2 1 1 1
//
// targetFreq: a e h t
//             1 1 2 2
//             a e h t
//             1 1 1 1
//             a e
//             1 1
//             h t
//             2 2
//             a h t
//             1 2 2
//             
// dfs(thehat): 3
//   dfs(aeht): 2
//     dfs(ae): 1
//       dfs(): 0
//   dfs(hhtt): 2
//     dfs(ht): 1
//   dfs(ahhtt): 3
//     dfs(hhtt)
//     

// 16ms 86.49% 44.8MB 87.64%
// recursive dyanamic programming
// O(N * T * 2^T) O(2^T + T)
// N: The number of stickers.
// T: The length of the target string. 
class Solution {
    private int dfs(Map<String, Integer> C, int[][] stickerFreqs,
                    String target) {
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
            targetFreq[c - 'a']++;
        }
        int rst = Integer.MAX_VALUE;
        for (int[] stickerFreq : stickerFreqs) {
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
                rst = Math.min(rst, cnt + 1);
            }
        }

        C.put(target, rst == Integer.MAX_VALUE ? -1 : rst);
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
