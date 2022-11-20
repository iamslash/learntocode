// Copyright (C) 2022 by iamslash

import java.util.*;

//        i 
// s: a a b b
//          j

//    i
// s: l e t e l t 
//              j

//        i
// s: aaaac
//        j

// 54ms 18.18% 76.1MB 8.88%
// greedy algorithm
// O(N) O(N)
class Solution {
    public int minMovesToMakePalindrome(String s) {
        int ans = 0;
        while (s.length() > 0) {
            int i = s.indexOf(s.charAt(s.length() - 1));
            if (i == s.length() - 1) {
                ans += i / 2;
            } else {
                ans += i;
                s = s.substring(0, i) + s.substring(i + 1);
            }
            s = s.substring(0, s.length() - 1);
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
