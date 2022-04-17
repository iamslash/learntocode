// Copyright (C) 2022 by iamslash

import java.util.*;

// 86ms 28.24% 121.1MB 89.47%
// math
// O(N) O(N)
class Solution {
    public int digArtifacts(int n, int[][] artifacts, int[][] dig) {
        Set<String> exSet = new HashSet<>();
        for (int[] pos : dig) {
            exSet.add(pos[0] + "," + pos[1]);
        }
        int cnt = 0;
        for (int[] rect : artifacts) {
            boolean done = true;
            for (int x = rect[0]; x <= rect[2]; ++x) {
                for (int y = rect[1]; y <= rect[3]; ++y) {
                    if (!exSet.contains(x + "," + y)) {
                        done = false;
                        break;
                    }
                }
            }
            if (done) {
                cnt++;
            }
        }
        return cnt;
    }
}

// 4ms 100.00% 113.1MB 94.41%
// hash set
// O(N) O(1)
class Solution {
    private boolean inside(int[] rect, boolean[][] cells) {
        for (int x = rect[0]; x <= rect[2]; ++x) {
            for (int y = rect[1]; y <= rect[3]; ++y) {
                if (!cells[x][y]) {
                    return false;
                }
            }
        }
        return true;
    }
    public int digArtifacts(int n, int[][] artifacts, int[][] dig) {
        int cnt = 0;
        boolean[][] cells = new boolean[n][n];
        for (int[] pos : dig) {
            cells[pos[0]][pos[1]] = true;
        }
        for (int[] rect : artifacts) {
            if (inside(rect, cells)) {
                cnt++;
            }
        }
        return cnt;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
