// Copyright (C) 2025 by iamslash

import java.util.*;


//      k: 3
// limits: 2 2
//   grid:
//
// 5 3 7
// 8 2 6
//
// 3 5 7
// 2 6 8

// 206ms 42.95% 80.06MB 7.61%
// priority queue
// O(N*M*lgN) O(N*M)
class Solution {
    public long maxSum(int[][] grid, int[] limits, int k) {
        int h = grid.length, w = grid[0].length;
        long sum = 0;
        Queue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]);

        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                pq.offer(new int[]{grid[y][x], y});
            }
        }

        while (k > 0 && !pq.isEmpty()) {
            int[] top = pq.poll();
            int val = top[0], row = top[1];

            if (limits[row] > 0) {
                sum += val;
                limits[row]--;
                k--;
            }
        }

        return sum;
    }
}

// sort
// 
class Solution {
    public long maxSum(int[][] grid, int[] limits, int k) {
        List<Integer> sumArr = new ArrayList<>();
        int i = 0;
        for(int[] row : grid){
            Arrays.sort(row);
            int j = row.length - 1;
            while(limits[i] > 0){
                sumArr.add(row[j]);
                j--;
                limits[i]--;
            }
            i++;
        }
        
        Collections.sort(sumArr,Comparator.reverseOrder());
        long sum = 0;
        for(int m=0;m<k;m++){
            sum += sumArr.get(m);
        }
        return sum;
    }
}

//      k: 2
// limits: 1 2
//   grid:
//
//  1 2
//  3 4
//
//  cands: 2 4 3
//         4 3 2

// 116ms 77.85% 78.19MB 17.29%
// sort
// O(H * W * lgH) O(K)
class Solution {
    public long maxSum(int[][] grid, int[] limits, int k) {
        int h = grid.length, w = grid[0].length;
        List<Integer> cands = new ArrayList<>();

        for (int y = 0; y < h; ++y) {
            Arrays.sort(grid[y]);
            // System.out.printf("y: %d, limits[y]\n", y);
            for (int x = w - 1; x >= 0 && limits[y] > 0; --x) {
                cands.add(grid[y][x]);
                limits[y]--;
            }
        }

        Collections.sort(cands, Comparator.reverseOrder());
        // System.out.println(cands);

        long sum = 0;
        for (int i = 0; i < k ; ++i) {
            sum += cands.get(i);
        }

        return sum;
    }
}
