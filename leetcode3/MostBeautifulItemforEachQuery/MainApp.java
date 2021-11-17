// Copyright (C) 2021 by iamslash

import java.util.*;

// items: 1,2 3,2 2,4 5,6 3,5

// 74ms 64.24% 95.8MB 86.49%
// sort, hash map
// O(NlgN) O(N)
class Solution {
    public int[] maximumBeauty(int[][] items, int[] queries) {
        Arrays.sort(items, (a, b) -> a[0] - b[0]);
        TreeMap<Integer, Integer> maxBeautyMap = new TreeMap<>();
        int maxBeauty = 0;
        for (int[] item : items) {
            int price = item[0], beauty = item[1];
            maxBeauty = Math.max(maxBeauty, beauty);
            maxBeautyMap.put(price, maxBeauty);
        }
        int[] ans = new int[queries.length];
        for (int i = 0; i < queries.length; ++i) {
            Integer key = maxBeautyMap.floorKey(queries[i]);
            if (key != null) {
                ans[i] = maxBeautyMap.get(key);
            }
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
