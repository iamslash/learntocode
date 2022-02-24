// Copyright (C) 2022 by iamslash

import java.util.*;

// s: 1212
//    1
//    12
//    1212
//     2
//
              
// 0 1 2 3 4 5 6 7 8 9
//       3 2 2 4 3 3 2

// Wrong Answer
//  for "3634957856984768367"
// hash set
// O(N^2) O(N)
class Solution {
    private boolean sameDigitCount(int[] freqs) {
        int cnt = 0;
        for (int i = 0; i < 10; ++i) {
            if (freqs[i] > 0 && cnt > 0 && freqs[i] != cnt) {
                return false;
            }
            if (freqs[i] > 0 && cnt == 0) {
                cnt = freqs[i];
            }
        }
        return true;
    }
    public int equalDigitFrequency(String s) {
        Set<String> strSet = new HashSet<>();
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            StringBuilder sb = new StringBuilder();
            int[] freqs = new int[10];
            for (int j = i; j < n; ++j) {
                char c = s.charAt(j);
                ++freqs[c-'0'];
                if (!sameDigitCount(freqs)) {
                    continue;
                }
                sb.append(c);
                strSet.add(sb.toString());
            }
        }
        return strSet.size();
    }
}

// 392ms 45.72% 43.8MB 90.86%
// hash set
// O(N^2) O(N)
class Solution {
    private boolean sameDigitCount(int[] freqs) {
        int cnt = 0;
        for (int i = 0; i < 10; ++i) {
            if (freqs[i] > 0 && cnt > 0 && freqs[i] != cnt) {
                return false;
            }
            if (freqs[i] > 0 && cnt == 0) {
                cnt = freqs[i];
            }
        }
        return true;
    }
    public int equalDigitFrequency(String s) {
        Set<String> strSet = new HashSet<>();
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            int[] freqs = new int[10];
            for (int j = i; j < n; ++j) {
                char c = s.charAt(j);
                ++freqs[c-'0'];
                if (sameDigitCount(freqs)) {
                    strSet.add(s.substring(i,j+1));
                }
            }
        }
        return strSet.size();
    }
}

// 93ms 90.34% 53.9MB 80.68%
// rolling hash
// O(N^2) O(N)
class Solution {
    public int equalDigitFrequency(String s) {
        final int MOD = 1_000_000_007;
        Set<Integer> numSet = new HashSet<>();
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            int[] freqs = new int[10];
            int uniq = 0, maxCnt = 0, rollingHash = 0;
            for (int j = i; j < n; ++j) {
                char c = s.charAt(j);
                int digit = c - '0';
                uniq += freqs[digit] == 0 ? 1 : 0;
                freqs[digit]++;
                maxCnt = Math.max(maxCnt, freqs[digit]);
                rollingHash = (rollingHash * 11 + digit + 1) % MOD;
                if (maxCnt * uniq == j - i + 1) {
                    numSet.add(rollingHash);
                }
            }
        }
        return numSet.size();
    }
}

// 198ms 63.07% 368.9MB 6.82%
// trie
// O(N^2) O(N)
class TrieNode {
    TrieNode[] next = new TrieNode[10];
    boolean seen;
}
class Solution {
    public int equalDigitFrequency(String s) {
        TrieNode trie = new TrieNode();
        int cnt = 0, n = s.length();
        for (int i = 0; i < n; ++i) {
            TrieNode u = trie;
            int[] freqs = new int[10];
            int uniq = 0, maxCnt = 0;
            for (int j = i; j < n; ++j) {
                int digit = s.charAt(j) - '0';
                uniq += freqs[digit] == 0 ? 1 : 0;
                freqs[digit]++;
                maxCnt = Math.max(maxCnt, freqs[digit]);
                if (u.next[digit] == null) {
                    u.next[digit] = new TrieNode();
                }
                u = u.next[digit];
                if (uniq * maxCnt == j - i + 1 && !u.seen) {
                    cnt++;
                    u.seen = true;
                }
            }
        }
        return cnt;
    }
}

// 667ms 33.52% 117.9MB 43.75%
// hash set
// O(N^2) O(N)
class Solution {
    private boolean sameDigitCount(int[] freqs) {
        int cnt = 0;
        for (int i = 0; i < 10; ++i) {
            if (freqs[i] > 0 && cnt > 0 && freqs[i] != cnt) {
                return false;
            }
            if (freqs[i] > 0 && cnt == 0) {
                cnt = freqs[i];
            }
        }
        return true;
    }
    public int equalDigitFrequency(String s) {
        Set<String> strSet = new HashSet<>();
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            int[] freqs = new int[10];
            int uniq = 0, maxCnt = 0;
            for (int j = i; j < n; ++j) {
                int digit = s.charAt(j) - '0';
                uniq += freqs[digit]++ == 0 ? 1 : 0;
                maxCnt = Math.max(maxCnt, freqs[digit]);
                if (uniq * maxCnt == j - i + 1) {
                    strSet.add(s.substring(i,j+1));
                }
            }
        }
        return strSet.size();
    }
}
