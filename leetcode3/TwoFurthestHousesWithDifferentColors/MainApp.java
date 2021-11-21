// Copyright (C) 2021 by iamslash

import java.util.*;

//         i
// colors: 1 1 1 6 1 1 1
//               j

//      n: 13
//                            j
// colors: 6 6 6 6 6 6 6 6 6 19 19 6 6
//                               k   

// 0ms 100.00% 37.1MB 11.11%
// brute force
// O(N) O(1)
class Solution {
    public int maxDistance(int[] colors) {
        int n = colors.length;
        if (colors[0] != colors[n-1]) {
            return n-1;
        }
        int j = -1, k = n;
        for (int i = 1; i < n-1; ++i) {
            if (colors[0] != colors[i]) {
                j = i;
                break;
            }
        }
        int leftMaxDist = Math.max(j, n-1-j);
        for (int i = n-2; i > 0; --i) {
            if (colors[n-1] != colors[i]) {
                k = i;
                break;
            }
        }
        int rightMaxDist = Math.max(k, n-1-k);
        return Math.max(leftMaxDist, rightMaxDist);
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
