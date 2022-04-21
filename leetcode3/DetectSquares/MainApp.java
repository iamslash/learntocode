// Copyright (C) 2022 by iamslash

import java.util.*;

// 87ms 74.63% 53.8MB 80.69%
// hash map
//   add: O(1) O(N)
// count: O(1) O(N)
class DetectSquares {
    List<int[]> coords = new ArrayList<>();
    int[][] cnts = new int[1001][1001];
    public void add(int[] point) {
        coords.add(point);
        cnts[point[0]][point[1]]++;
    }    
    public int count(int[] point) {
        int cnt = 0, x1 = point[0], y1 = point[1];
        for (int[] coord : coords) {
            int x3 = coord[0], y3 = coord[1];
            if (x1 == x3 || y1 == y3 ||
                (Math.abs(x1 - x3) != Math.abs(y1 - y3))) {
                continue;
            }
            cnt += cnts[x1][y3] * cnts[x3][y1];
        }
        return cnt;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
