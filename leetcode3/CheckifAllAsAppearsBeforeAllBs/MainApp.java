// Copyright (C) 2021 by iamslash

import java.util.*;

//        i
// s: a b a b
//      j

// 1ms 78.17% 38.6MB 80.96%
// two pointers
// O(N) O(1)
class Solution {
    public boolean checkString(String s) {
        int aIdx = -1, bIdx = 100;
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (c == 'a') {
                aIdx = i;
            } else {
                bIdx = i;
            }
            if (aIdx > bIdx) {
                return false;
            }
        }
        return true; 
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
