// Copyright (C) 2022 by iamslash

import java.util.*;

// 1ms 80.00% 40.4MB 80.00%
// brute force
// O(N) O(N)
class Solution {
    public String digitSum(String s, int k) {
        StringBuilder sb = new StringBuilder(s);
        while (sb.length() > k) {
            StringBuilder tmpSb = new StringBuilder();
            for (int i = 0; i < sb.length(); i += k) {
                int unit = 0;
                for (int j = 0; j < k && (i + j) < sb.length(); ++j) {
                    unit += sb.charAt(i + j) - '0';
                }
                tmpSb.append(String.valueOf(unit));
            }
            sb = tmpSb;
            // System.out.println(sb.toString());
        }
        return sb.toString();
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
