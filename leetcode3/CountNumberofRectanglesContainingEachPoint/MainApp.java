// Copyright (C) 2022 by iamslash

import java.util.*;

// 788ms 25.97% 103.6MB 39.64%
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

//  rects: 1,2 2,3 2,5
// points: 2,1 1,4
//
//     es: 1,2 2,3 2,5 2,1,0 1,4,1
//         1,2 1,4,1 2,3 2,5 2,1,0
//           i

// 48ms 99.22% 70.3MB 81.09%
// line sweep, sort
// O(NlgN) O(N)
class Solution {
    public int[] countRectangles(int[][] rects, int[][] points) {
        int n = rects.length, m = points.length;
        int[][] es = new int[n + m][];
        for (int i = 0; i < n; ++i) {
            es[i] = rects[i];
        }
        for (int i = 0; i < m; ++i) {
            es[n + i] = new int[]{points[i][0], points[i][1], i};
        }
        Arrays.sort(es, (a, b) -> {
                if (a[0] != b[0]) {
                    return b[0] - a[0];
                }
                return a.length - b.length;
            });
        int[] cnts = new int[101];
        int[] ans = new int[m];
        for (int[] e : es) {
            if (e.length == 2) {
                for (int y = 0; y <= e[1]; ++y) {
                    cnts[y]++;
                }
            } else {
                ans[e[2]] = cnts[e[1]];
            }
        }
        return ans;
    }
}
