// Copyright (C) 2022 by iamslash

import java.util.*;

// line sweep, binary search
class Solution {
    public int[] countRectangles(int[][] rects, int[][] points) {
        int n = rects.length;
        // {height : [len,...]}
        Map<Integer, ArrayList<Integer>> h2lMap = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            int height = rects[i][1], width = rects[i][0];
            h2lMap.putIfAbsent(height, new ArrayList<>());
            h2lMap.get(height).add(width);
        }
        for (int h : h2lMap.keySet()) {
            Collections.sort(h2lMap.get(h));
        }
        int[] ans = new int[points.length];
        for (int i = 0; i < points.length; ++i) {
            int x = points[i][0], y = points[i][1], cnt = 0;
            for (int j = y; j <= 100; ++j) {
                if (h2lMap.containsKey(j)) {
                    List<Integer> widthList = h2lMap.get(j);
                    cnt += widthList.size() - lessCnt(widthList, x);
                }                   
            }
            ans[i] = cnt;
        }
        return ans;
    }
    private int lessCnt(List<Integer> widthList, int x) {
        int n = widthList.size(), lo = 0, hi = n - 1, ans = n;
        while (lo <= hi) {
            int mi = lo + (hi - lo) / 2;
            if (widthList.get(mi) >= x) {
                ans = mi;
                hi = mi - 1;
            } else {
                lo = mi + 1;
            }
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
