// Copyright (C) 2024 by iamslash

import java.util.*;

//    k: 2
// nums: 1 1 1 2 2 3
// cnts: 1 2 3
//       3 2 1
// idxs: 1 2 3
//       1 2 3

// 12ms 84.98% 48.3MB 66.97%
// sort
// O(NlgN) O(N)
class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        int[] cnts = new int[20_001];
        for (int num : nums) {
            cnts[num + 10_000]++;
        }
        Integer[] idxs = new Integer[20_001];
        for (int i = 0; i < 20_001; ++i) {
            idxs[i] = i;
        }
        Arrays.sort(idxs, (i, j) -> cnts[j] - cnts[i]);
        int[] ans = new int[k];
        for (int i = 0; i < k; ++i) {
            ans[i] = idxs[i] - 10_000;
        }
        return ans;
    }
}

//    k: 2
// nums: 1 1 1 2 2 3
// cnts: 1 2 3
//       3 2 1
// bLst: 0 1 2 3 4 5 6
//         3 2 1

// 11ms 93.48% 48.6MB 36.98%
// hash map
// O(N) O(N)
class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        int n = nums.length;
        // numList[freq]: num
        List<Integer>[] numList = new List[n + 1];
        Map<Integer, Integer> freqMap = new HashMap<Integer, Integer>();
        for (int num : nums) {
            freqMap.put(num, freqMap.getOrDefault(num, 0) + 1);
        }

        for (int num : freqMap.keySet()) {
            int freq = freqMap.get(num);
            if (numList[freq] == null) {
                numList[freq] = new ArrayList<>();
            }
            numList[freq].add(num);
        }

        int[] ans = new int[k];
        int pos = 0;
        for (int freq = n; freq >= 0; --freq) {
            if (numList[freq] != null) {
                int m = numList[freq].size();
                for (int i = 0; i < m && pos < k; ++i, ++pos) {
                    ans[pos] = numList[freq].get(i);
                }
            }
        }

        return ans;
    }
}
