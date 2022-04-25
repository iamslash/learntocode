// Copyright (C) 2022 by iamslash

import java.util.*;

// 398ms 50.00% 118.8MB 50.00%
// hash set
// O(N) O(N)
class Solution {
    private void updateCoordSet(Set<Integer> coordSet, int cx, int cy, int r) {
        int rr = r * r;
        for (int x = -r; x <= r; ++x) {
            for (int y = -r; y <= r; ++y) {
                // System.out.printf("x: %d, y: %d, r: %d\n", x, y, r);
                if (x * x + y * y <= rr) {
                    coordSet.add((cx + x) * 1000 + (cy + y));
                }
            }
        }
    }
    public int countLatticePoints(int[][] circles) {
        Set<Integer> coordSet = new HashSet<>();
        for (int[] circle : circles) {
            updateCoordSet(coordSet, circle[0], circle[1], circle[2]);
        }
        return coordSet.size();
    }
}

// 53ms 75.00% 42MB 75.00%
// outline
// O(N) O(1)
class Solution {
    public int countLatticePoints(int[][] circles) {
        int ans = 0;
        int minX = 500, maxX = -500, minY = 500, maxY = -500;
        for (int[] circle : circles) {
            int cx = circle[0], cy = circle[1], r = circle[2];
            minX = Math.min(minX, cx-r);
            maxX = Math.max(maxX, cx+r);
            minY = Math.min(minY, cy-r);
            maxY = Math.max(maxY, cy+r);
        }
        for (int x = minX; x <= maxX; ++x) {
            for (int y = minY; y <= maxY; ++y) {
                for (int[] circle : circles) {
                    int cx = circle[0], cy = circle[1], r = circle[2];
                    if ((cx-x) * (cx-x) + (cy-y) * (cy-y) <= r * r) {
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
