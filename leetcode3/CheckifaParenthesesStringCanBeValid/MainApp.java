// Copyright (C) 2022 by iamslash

import java.util.*;

// locked: 010100
//      s: ))()))
//         *)*)**

// greedy, back and forth
// O(N) O(N)
class Solution {
    private boolean valid(String s, String locked, char op) {
    }
    public boolean canBeValid(String s, String locked) {
        if (s.length() % 2 != 0) {
            return false;
        }
        return valid(s, locked, '(') && valud(s, locked, ')');
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
