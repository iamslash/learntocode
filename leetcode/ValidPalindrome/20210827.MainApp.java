// Copyright (C) 2021 by iamslash

// 5ms 44.29% 40.2MB 21.07%
// two pointers
// O(N) O(1)
class Solution {
    public boolean isPalindrome(String s) {
        int n = s.length(), i = 0, j = n - 1;
        while (i < j) {
            while (i < j && !Character.isLetterOrDigit(s.charAt(i))) {
                ++i;
            }
            while (i < j && !Character.isLetterOrDigit(s.charAt(j))) {
                --j;
            }
            if (Character.toLowerCase(s.charAt(i)) !=
                Character.toLowerCase(s.charAt(j))) {
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
