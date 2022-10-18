// Copyright (C) 2022 by iamslash

import java.util.*;

// pref: 5 2 0 3 1
// orig: ? ? ? ? ?
// pref: 0101 0010 0000 0011 0001
// orig: 0101 0101 0010 0011 0010

// 3ms 78.95% 106.3MB 31.10%
// bit manipulation
// O(N) O(1)
class Solution {
    public int[] findArray(int[] pref) {
        int n = pref.length, prev = 0;
        for (int i = 0; i < n; ++i) {
            int temp = pref[i];
            pref[i] = pref[i] ^ prev;
            prev = temp;
        }
        return pref;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
