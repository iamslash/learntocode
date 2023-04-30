// Copyright (C) 2023 by iamslash

import java.util.*;

// 10
// 0,4 0,9 0,0 6,7
// 0,9

// 104ms 39.02%
// sort
// O(NlgN) O(N)
class Solution {
    private void dump(List<int[]> AA) {
        for (int[] A : AA) {
            System.out.printf("%d,%d ", A[0], A[1]);
        }
        System.out.println();
    }
    public int[][] findMaximalUncoveredRanges(int n, int[][] ranges) {
        List<int[]> merged = new ArrayList<>();
        Arrays.sort(ranges, (a, b) -> a[0] - b[0]);
        for (int i = 0; i < ranges.length; ++i) {
            if (i == 0 || merged.get(merged.size() - 1)[1] < ranges[i][0]) {
                merged.add(new int[]{ranges[i][0], ranges[i][1]});
            } else {
                int[] last = merged.get(merged.size() - 1);
                last[1] = Math.max(last[1], ranges[i][1]);
            }
            // dump(merged);
        }
        List<int[]> ans = new ArrayList<>();
        int prvBeg = 0;
        for (int[] range : merged) {
            if (prvBeg < range[0]) {
                ans.add(new int[]{prvBeg, range[0] - 1});
            }
            prvBeg = range[1] + 1;
        }
        if (prvBeg < n) {
            ans.add(new int[]{prvBeg, n - 1});
        }
        return ans.toArray(new int[0][]);
    }
}
