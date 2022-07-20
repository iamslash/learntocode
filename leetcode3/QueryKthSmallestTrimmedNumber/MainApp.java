// Copyright (C) 2022 by iamslash

import java.util.*;

//    nums: 102 473 251 814
// queries: 1,1 2,3 4,2 1,2
//
//            2   3   1   4
//          102 473 251 814
//           02  73  51  14
//           02  73  51  14
//
//     ans: 2 2 1 0

// 193ms 25.00% 46MB 87.50%
// hash map, sort
// O(NNlgN) O(N)
class Solution {
    public int[] smallestTrimmedNumbers(String[] nums, int[][] queries) {
        Map<Integer, List<Pair<Integer, String>>> sortedNumsMap = new HashMap<>();
        int n = queries.length, numLen = nums[0].length(), numsCnt = nums.length;
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            int ordIdx = queries[i][0], trmIdx = queries[i][1];
            if (!sortedNumsMap.containsKey(trmIdx)) {
                List<Pair<Integer, String>> sortedNums = new ArrayList<>();
                for (int j = 0; j < numsCnt; ++j) {
                    // System.out.printf("i: %d, j: %d, trmIdx: %d, ordIdx: %d, numLen: %d, numCnt: %d\n", i, j, trmIdx, ordIdx, numLen, numsCnt);
                    sortedNums.add(new Pair<Integer, String>(j, nums[j].substring(numLen - trmIdx)));
                }
                Collections.sort(sortedNums, (a, b) -> a.getValue().compareTo(b.getValue()));
                sortedNumsMap.put(trmIdx, sortedNums);
            }
            ans[i] = sortedNumsMap.get(trmIdx).get(ordIdx-1).getKey();
        }
        return ans;
    }
}
