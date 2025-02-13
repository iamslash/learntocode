// Copyright (C) 2025 by iamslash

import java.util.*;

// 1 7 3
// 9 8 2
// 4 5 6
//
// 8
//

// Idea: sort
//
// The elements which have same i - j
// in same diagnal line.

// 8ms 25.88% 45.54MB 80.92%
// hash map, sort
// O(NNlgN) O(N)
class Solution {
    public int[][] sortMatrix(int[][] grid) {
        int n = grid.length;
        Map<Integer, List<Integer>> diagMap = new HashMap<>();

        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < n; ++x) {
                int key = y - x;
                diagMap.putIfAbsent(key, new ArrayList<>());
                diagMap.get(key).add(grid[y][x]);
            }
        }

        for (int key : diagMap.keySet()) {
            List<Integer> numList = diagMap.get(key);
            if (key >= 0) {
                Collections.sort(numList, Collections.reverseOrder());
            } else {
                Collections.sort(numList);
            }
        }

        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < n; ++x) {
                int key = y - x;
                List<Integer> numList = diagMap.get(key);
                grid[y][x] = numList.get(0);
                numList.remove(0);
            }
        }

        return grid;
    }
}

// 1 7 3
// 9 8 2
// 4 5 6

// 1ms 100.00% 46.MB 11.81%
// sort
// O(NN) O(1)
class Solution {
    public int[][] sortMatrix(int[][] grid) {
        int n = grid.length;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                int k = i, l = j;
                if (j <= i) {
                    while (k > 0 && l > 0 && grid[k][l] > grid[k - 1][l - 1]) {
                        int temp = grid[k - 1][l - 1];
                        grid[k - 1][l - 1] = grid[k][l];
                        grid[k--][l--] = temp;
                    }
                } else {
                    while (k > 0 && l > 0 && grid[k][l] < grid[k - 1][l - 1]) {
                        int temp = grid[k - 1][l - 1];
                        grid[k - 1][l - 1] = grid[k][l];
                        grid[k--][l--] = temp;
                    }
                }
            }
        }
        return grid;
    }
}
