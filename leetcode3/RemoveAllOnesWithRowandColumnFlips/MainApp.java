// Copyright (C) 2021 by iamslash

import java.util.*;

// 1ms 98.89% 61.6MB 51.11%
// xor
// O(HW) O(W)
class Solution {
    private boolean isEqual(int[] a, int[] b) {
        int n = a.length;
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }
    private int[] getXor(int[] a) {
        int n = a.length;
        int[] rst = new int[n];
        for (int i = 0; i < n; ++i) {
            rst[i] = 1 - a[i];
        }
        return rst;
    }
    public boolean removeOnes(int[][] grid) {
        int[] firstRowXor = getXor(grid[0]);
        int h = grid.length;
        for (int y = 1; y < h; ++y) {
            if (!isEqual(grid[0], grid[y]) &&
                !isEqual(firstRowXor, grid[y])) {
                return false;
            }
        }
        return true;
    }
}

// 1ms 98.89% 61.1MB 75.56%
// xor
// O(HW) O(W)
class Solution {
    private boolean compare(int[] a, int[] b) {
        int diff = 0, n = a.length;
        for (int i = 0; i < n; ++i) {
            diff += a[i] ^ b[i];
        }
        return diff == 0 || diff == n;
    }
    public boolean removeOnes(int[][] grid) {
        int n = grid.length;
        for (int i = 1; i < n; ++i) {
            if (!compare(grid[i], grid[0])) {
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
