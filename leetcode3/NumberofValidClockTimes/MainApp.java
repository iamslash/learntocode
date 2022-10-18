// Copyright (C) 2022 by iamslash

import java.util.*;

// ??:??
// ?3:??
// ?7:??

// 0ms 100.00% 42.2MB 34.37%
// brute force
// O(1) O(1)
class Solution {
    public int countTime(String time) {
        if (time.equals("??:??")) {
            return 1440;
        }
        int ans = 1;
        if (time.charAt(0) == '?' && time.charAt(1) == '?') {
            ans *= 24;
        } else if (time.charAt(0) == '?') {
            if (time.charAt(1) < '4') {
                ans *= 3;
            } else {
                ans *= 2;
            }
        } else if (time.charAt(1) == '?') {
            if (time.charAt(0) < '2') {
                ans *= 10;
            } else {
                ans *= 4;
            }
        }
        if (time.charAt(3) == '?') {
            ans *= 6;
        }
        if (time.charAt(4) == '?') {
            ans *= 10;
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
