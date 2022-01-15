// Copyright (C) 2022 by iamslash

import java.util.*;

// cells: 0 1 0 1 1 0 0 1    7
//        0 1 1 0 0 0 0 0    6   
//        0 1 1 0 0 0 0 0    5

// hash map
// O(N) O(N)
class Solution {
  private int[] transform(int[] cells) {
    int[] rst = new int[cells.length];
    for (int i = 1; i < cells.length - 1; ++i) {
      rst[i] = cells[i-1] == cells[i+1] ? 1 : 0;
    }
    return rst;
  }
  public int[] prisonAfterNDays(int[] cells, int n) {
    Map<String, Integer> cellsMap = new HashMap<>();
    while (n > 0) {
      String s = Arrays.toString(cells);
      cellsMap.put(s, n--);
      cells = transform(cells);
      s = Arrays.toString(cells);
      if (cellsMap.containsKey(s)) {
        n %= cellsMap.get(s) - n;
      }
    }
    return cells;
  }
}

public class MainApp {
  public static void main(String[] args) {
    char[] chars = new char[]{'H','E','L','L','O'};
    int[] cells = new int[]{0,0,1,1};
    System.out.println(String.valueOf(cells));  // [I@59f95c5d
    System.out.println(Arrays.toString(cells)); // [0, 0, 1, 1]
    System.out.println(String.valueOf(chars));  // HELLO    
  }
}
