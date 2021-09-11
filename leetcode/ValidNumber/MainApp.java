// Copyright (C) 2021 by iamslash

import java.util.*;

// 3ms 38.39% 39.8MB 17.97%
// flags
// O(N) O(1)
class Solution {
    public boolean isNumber(String s) {
        s = s.trim();
        boolean isDot = false;
        boolean isE = false;
        boolean isNumber = false;
        boolean isNumberAfterE = false;
        for (int i = 0; i < s.length(); ++i) {
            if (Character.isDigit(s.charAt(i))) {
                isNumber = true;
                isNumberAfterE = true;
            } else if (s.charAt(i) == '.') {
                if (isE || isDot) {
                    return false;
                }
                isDot = true;
            } else if (s.charAt(i) == 'e' || s.charAt(i) == 'E') {
                if (isE || !isNumber) {
                    return false;
                }
                isE = true;
                isNumberAfterE = false;
            } else if (s.charAt(i) == '-' || s.charAt(i) == '+') {
                if (i != 0 && s.charAt(i-1) != 'e') {
                    return false;
                }
            } else {
                return false;
            }
        }
        return isNumber && isNumberAfterE;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
