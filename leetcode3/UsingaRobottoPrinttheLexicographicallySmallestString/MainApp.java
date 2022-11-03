// Copyright (C) 2022 by iamslash

import java.util.*;

// s:  
// t:  
// f: a z
//    0 0
// p: a z z

// 189ms 84.00% 72.1MB 78.47%
// hash map, stack
// O(N) O(N)
class Solution {
    private boolean isSmallest(int[] freqs, int pos) {
        for (int i = 0; i < pos; ++i) {
            if (freqs[i] > 0) {
                return false;
            }
        }
        return true;
    }
    public String robotWithString(String s) {
        int n = s.length();
        int[] freqs = new int[26];
        for (char c : s.toCharArray()) {
            freqs[c - 'a']++;
        }
        Deque<Integer> deq = new ArrayDeque<>();
        StringBuilder ans = new StringBuilder();
        for (char c : s.toCharArray()) {
            int i = c - 'a';
            deq.addLast(i);
            freqs[i]--;
            // System.out.println(deq);
            while (!deq.isEmpty() && isSmallest(freqs, deq.peekLast())) {
                ans.append((char)('a' + deq.pollLast()));
            }
        }
        return ans.toString();
    }
}
