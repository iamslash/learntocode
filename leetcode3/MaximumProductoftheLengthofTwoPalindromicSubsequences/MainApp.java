// Copyright (C) 2021 by iamslash

import java.util.*;

// 7ms 99.39% 39.1MB 83.78%
// bit manipulation, iterative dnamoc programming
// O(2^(2N)) O(1)
// O(4^N) O(1)
class Solution {
    private int palLen(String s, int bm) {
        int p1 = 0, p2 = s.length(), len = 0;
        while (p1 <= p2) {
            if ((bm & (1 << p1)) == 0) {
                ++p1;
            } else if ((bm & (1 << p2)) == 0) {
                --p2;
            } else if (s.charAt(p1) != s.charAt(p2)) {
                return 0;
            } else {
                len += 1 + (p1 != p2 ? 1 : 0);
                ++p1;
                --p2;
            }
        }
        return len;
    }
    public int maxProduct(String s) {
        // s.length() <= 12
        int n = s.length();
        int[] C = new int[4096];
        int maxProd = 0, maxBm = (1 << n) - 1;
        for (int a = 1; a <= maxBm; ++a) {
            C[a] = palLen(s, a);
        }
        for (int a = maxBm; a > 0; --a) {
            if (C[a] * (n - C[a]) > maxProd) {
                int begBm = maxBm^a;
                for (int b = begBm; b > 0; b = (b-1) & begBm) {
                    maxProd = Math.max(maxProd, C[a] * C[b]);
                }
            }
        }
        return maxProd;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
