// Copyright (C) 2023 by iamslash

import java.util.*;

//   k: 2
// arr: 1 4 1 3
//                

// 135ms 50.34% 62.4MB 31.61%
// sort
// O(NlgN) O(K)
class Solution {
    public long makeSubKSumEqual(int[] arr, int k) {
        int n = arr.length;
        long ans = 0;
        for (int i = 0; i < k; ++i) {
            List<Integer> numList = new ArrayList<>();
            for (int j = i; arr[j] != 0; j = (j + k) % n) {
                numList.add(arr[j]);
                arr[j] = 0;
            }
            if (numList.size() > 0) {
                Collections.sort(numList);
                int median = numList.get(numList.size() / 2);
                for (int num : numList) {
                    ans += Math.abs(num - median);
                }
            }
        }
        return ans;
    }
}
