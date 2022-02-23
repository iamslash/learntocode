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

public class MainApp {
  public static void main(String[] args) {
  }
}
