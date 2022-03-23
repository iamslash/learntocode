// Copyright (C) 2022 by iamslash

import java.util.*;

// 22ms 93.98% 48.3MB 96.30%
// sort
// O(NlgN) O(N)
class Solution {
    private int compareStr(String a, String b) {
        if (a.length() == b.length()) {
            int n = a.length();
            for (int i = 0; i < n; ++i) {
                if (a.charAt(i) != b.charAt(i)) {
                    return a.charAt(i) - b.charAt(i);
                }
            }
            return 0;
        }
        return a.length() - b.length();
    }
    public String kthLargestNumber(String[] numStrs, int k) {
        int n = numStrs.length;
        Arrays.sort(numStrs, (a, b) -> {
                return compareStr(a, b);
            });
        return numStrs[n-k];
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
