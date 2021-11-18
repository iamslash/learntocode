// Copyright (C) 2021 by iamslash

import java.util.*;

// hash map
// O(N) O(N)
class Solution {
    public List<List<Long>> splitPainting(int[][] segments) {
        Map<Long, Long> colMap = new TreeMap<>();
        for (int[] seg : segments) {
            colMap.put((long)seg[0], colMap.getOrDefault((long)seg[0], 0L) + (long)seg[2]);
            colMap.put((long)seg[1], colMap.getOrDefault((long)seg[1], 0L) - (long)seg[2]);
        }
        List<List<Long>> ans = new ArrayList<>();
        long prvTs = 0, prvCol = 0;
        for (Long key : colMap.keySet()) {
            if (prvTs > 0) {
                ans.add(Arrays.asList(prvTs, key, prvCol));
            }
            prvTs = key;
            prvCol += colMap.get(key);
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
