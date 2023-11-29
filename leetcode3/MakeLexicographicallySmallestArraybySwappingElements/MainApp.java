// Copyright (C) 2023 by iamslash

import java.util.*;

// limit: 2
//        i
//  nums: 1 5 3 9 8

// limit: 3
//        i
//  nums: 1 7 6 18 2 1
//        0 1 2  3 4 5
//                        i
//     nums: 1 1 2 6 7 18
//           0 5 4 2 1  3
//  idxList: 0 2 3
//           5 1
//           4

// 86ms 64.27% 65.5MB 53.32%
// sort
// O(NlgN) O(N)
class Solution {
    public int[] lexicographicallySmallestArray(int[] nums, int limit) {
        int n = nums.length;
        int[][] numIdxs = new int[n][2];
        int[] ans = new int[n];
        List<List<Integer>> idxsList = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            numIdxs[i][0] = nums[i];
            numIdxs[i][1] = i;
        }
        Arrays.sort(numIdxs, (a, b) -> a[0] - b[0]);
        for (int i = 0; i < n; ++i) {
            if (i == 0 || numIdxs[i][0] - numIdxs[i - 1][0] > limit) {
                idxsList.add(new ArrayList<>());
            }
            idxsList.get(idxsList.size() - 1).add(numIdxs[i][1]);
        }
        for (List<Integer> idxs : idxsList) {
            List<Integer> sortedIdxList = new ArrayList<>(idxs);
            Collections.sort(sortedIdxList);
            for (int j = 0; j < idxs.size(); ++j) {
                ans[sortedIdxList.get(j)] = nums[idxs.get(j)];
            }
        }
        return ans;
    }
}
