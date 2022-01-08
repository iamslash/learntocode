// Copyright (C) 2021 by iamslash

import java.util.*;

// 43ms 21.19% 115.4MB 8.30%
// math
// O(NlgN) O(N)
class Solution {
    public int[][] kClosest(int[][] points, int k) {
        int[][] dists = new int[points.length][];
        for (int i = 0; i < points.length; ++i) {
            int[] pt = points[i];
            dists[i] = new int[]{pt[0], pt[1], pt[0]*pt[0] + pt[1]*pt[1]};
        }
        Arrays.sort(dists, (a, b) -> a[2] - b[2]);
        int[][] ans = new int[k][];
        for (int i = 0; i < k; ++i) {
            ans[i] = new int[]{dists[i][0], dists[i][1]};
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
