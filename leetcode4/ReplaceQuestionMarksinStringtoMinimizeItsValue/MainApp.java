// Copyright (C) 2024 by iamslash

import java.util.*;

// 66ms 58.54% 46.7MB 31.59%
// sort
// O(NlgN) O(N)
class Solution {
    public String minimizeStringValue(String s) {
        int n = s.length();
        int[] freqs = new int[26];
        List<Character> chrList = new ArrayList<>();
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) != '?') {
                freqs[s.charAt(i) - 'a']++;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) == '?') {
                int minIdx = -1;
                int minCnt = Integer.MAX_VALUE;
                for (int j = 25; j >= 0; --j) {
                    if (freqs[j] <= minCnt) {
                        minCnt = freqs[j];
                        minIdx = j;
                    }
                }
                char minChr = (char)('a' + minIdx);
                chrList.add(minChr);
                freqs[minIdx]++;
            }
        }

        Collections.sort(chrList);

        for (int i = 0, j = 0; i < n; ++i) {
            if (s.charAt(i) == '?') {
                sb.append(chrList.get(j++));
            } else {
                sb.append(s.charAt(i));
            }
        }

        return sb.toString();
    }
}

// 12ms 99.58% 45.5MB 95.43%
// bucket sort
// O(N) O(N)
class Solution {
    public String minimizeStringValue(String s) {
        int n = s.length();
        int questionCnt = 0;
        int[] freqs = new int[26];
        int[] replaceCnts = new int[26];        
        char[] chrs = s.toCharArray();

        // First pass: Count the frequency of each character and number of '?'
        for (char c : chrs) {
            if (c != '?') {
                freqs[c - 'a']++;
            } else {
                questionCnt++;
            }
        }

        // Find the minimum frequency of any character in freqs
        int minFreq = Integer.MAX_VALUE;
        for (int freq : freqs) {
            minFreq = Math.min(minFreq, freq);
        }

        // Distribute the '?' replacements to achieve minimal cost
        while (questionCnt > 0) {
            for (int i = 0; i < 26 && questionCnt > 0; i++) {
                if (freqs[i] == minFreq) {
                    replaceCnts[i]++;
                    freqs[i]++;
                    questionCnt--;
                }
            }
            minFreq++;
        }

        // Replace all '?' in the original string with the determined chrs
        int pos = 0;
        for (int i = 0; i < n; i++) {
            if (chrs[i] == '?') {
                // Find the next letter with available replacements
                while (replaceCnts[pos] == 0) {
                    pos++;
                }
                chrs[i] = (char) ('a' + pos);
                replaceCnts[pos]--;
            }
        }

        // Return the modified string
        return new String(chrs);
    }
}
