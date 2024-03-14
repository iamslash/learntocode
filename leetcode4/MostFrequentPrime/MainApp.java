// Copyright (C) 2024 by iamslash

import java.util.*;

// 9ms 90.66% 44.1MB 86.85%
// dfs
// O(8 * H * W * (H + W)) O(8 * H * W * (H + W))
class Solution {

    private boolean isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        if (n == 2) {
            return true;
        }
        if (n % 2 == 0) {
            return false;
        }
        int sqrtn = (int) Math.sqrt(n);
        for (int p = 3; p <= sqrtn; p += 2) {
            if (n % p == 0) {
                return false;
            }
        }
        return true;
    }

    private void dfs(int[][] mat, List<Integer> numList, int dy, int dx,
                     int prevNum, int y, int x) {
        int h = mat.length, w = mat[0].length;
        if (y < 0 || y >= h || x < 0 || x >= w) {
            return;
        }
        int num = prevNum * 10 + mat[y][x];
        if (num >= 10) {
            numList.add(num);
        }

        dfs(mat, numList, dy, dx, num, y + dy, x + dx);
    }

    public int mostFrequentPrime(int[][] mat) {
        List<Integer> numList = new ArrayList<>();
        int h = mat.length, w = mat[0].length;
        int[] dx = {0, 0, 1, 1, 1, -1, -1, -1};
        int[] dy = {1, -1, 0, 1, -1, 0, 1, -1};

        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                for (int d = 0; d < 8; ++d) {
                    dfs(mat, numList, dy[d], dx[d], 0, y, x);
                }
            }
        }

        Map<Integer, Integer> numMap = new HashMap<>();
        for (int num : numList) {
            if (!isPrime(num)) {
                continue;
            }
            numMap.put(num, numMap.getOrDefault(num, 0) + 1);
        }

        int maxCnt = 0, maxNum = -1;
        for (Map.Entry<Integer, Integer> entry : numMap.entrySet()) {
            int key = entry.getKey();
            int val = entry.getValue();
            if (val > maxCnt || (val == maxCnt && key > maxNum)) {
                maxCnt = val;
                maxNum = key;
            }
        }

        return maxNum;
    }
}
