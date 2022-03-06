// Copyright (C) 2022 by iamslash

import java.util.*;

// 3ms 100.00% 48.4MB 16.67%
// brute frce
// O(HW) O(HW)
class Solution {
    public List<String> cellsInRange(String s) {
        String[] block = s.split(":");
        char y0 = block[0].charAt(1);
        char x0 = block[0].charAt(0);
        char y1 = block[1].charAt(1);
        char x1 = block[1].charAt(0);
        int h = y1 - y0, w = x1 - x0;
        // System.out.printf("y0: %c, x0: %c, y1: %c, x1: %c, h: %d, w: %d\n", y0, x0, y1, x1, h, w);
        List<String> ans = new ArrayList<>();
        for (int x = 0; x <= w; ++x) {
            for (int y = 0; y <= h; ++y) {
                StringBuilder cell = new StringBuilder();
                cell.append((char)(x0+x));
                cell.append((char)(y0+y));
                ans.add(cell.toString());
            }
        }
        return ans;
    }
}

// 6ms 83.33% 47.MB 50.00%
// brute force
// O(HW) O(HW)
class Solution {
    public List<String> cellsInRange(String s) {
        List<String> ans = new ArrayList<>();
        for (char a = s.charAt(0); a <= s.charAt(3); ++a) {
            for (char b = s.charAt(1); b <= s.charAt(4); ++b) {
                ans.add("" + a + b);
            }
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
