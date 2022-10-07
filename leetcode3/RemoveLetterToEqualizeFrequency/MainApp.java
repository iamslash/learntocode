// Copyright (C) 2022 by iamslash

import java.util.*;

//         word: abbcc
// cnts2freqMap: 1 2
//               1 2
//
//         word: aaabbcc
// cnts2freqMap: 3 2
//               1 2
//
//         word: abbcc
// cnts2freqMap: 3 4
//               1 9
//
//         word: aaabbcc
// cnts2freqMap: 1 2
//               9 1
//
//         word: cbccca
// cnts2freqMap: 1 4
//               2 1

// 3ms 32.90% 42.2MB 24.97%
// hash map
// O(N) O(N)
// difficult
class Solution {
    public boolean equalFrequency(String word) {
        if (word.length() == 1 || word.length() == 2) {
            return true;
        }
        int[] cnts = new int[26];
        for (char c : word.toCharArray()) {
            cnts[c-'a']++;
        }
        Arrays.sort(cnts);
        List<Integer> freqList = new ArrayList<>();
        for (int i = 0; i < 26; ++i) {
            if (cnts[i] > 0) {
                freqList.add(cnts[i]);
            }
        }
        Integer[] freqs = freqList.toArray(new Integer[0]);
        int n = freqs.length;
        if (n == 1) {
            return true;
        } else if (freqs[0] == freqs[n-2] &&
                   freqs[n-2] == freqs[n-1] &&
                   freqs[0] == 1) {
            return true;
        } else if (freqs[0] == freqs[n-2] &&
                   freqs[n-1] - freqs[0] == 1) {
            return true;
        } else if (freqs[0] == 1 && freqs[1] == freqs[n-1]) {
            return true;
        }
        return false;
    }
}
