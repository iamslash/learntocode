// Copyright (C) 2022 by iamslash

import java.util.*;

// 5ms 37.83% 113.3MB 25.33%
// matrix
// O(N^2) O(1)
class Solution {
    public boolean checkValid(int[][] matrix) {
        int n = matrix.length;
        for (int y = 0; y < n; ++y) {
            Set<Integer> rowSet = new HashSet<>();
            Set<Integer> colSet = new HashSet<>();
            for (int x = 0; x < n; ++x) {
                rowSet.add(matrix[y][x]);
                colSet.add(matrix[x][y]);
            }
            if (rowSet.size() < n || colSet.size() < n) {
                return false;
            }
        }
        return true;
    }
}

// 6ms 85.49% 84MB 80.88%
// xor
// O(N^2) O(1)
class Solution {
    public boolean checkValid(int[][] matrix) {
        int n = matrix.length;
        for (int y = 0; y < n; ++y) {
            int rXor = 0, cXor = 0;            
            for (int x = 0; x < n; ++x) {
                rXor ^= matrix[y][x] ^ (x + 1);
                cXor ^= matrix[x][y] ^ (x + 1);
            }
            if (rXor != 0 || cXor != 0) {
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
