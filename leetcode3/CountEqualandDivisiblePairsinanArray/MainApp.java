// Copyright (C) 2022 by iamslash

import java.util.*;

//    k: 2
// nums: 3 1 2 2 2 1 3
//       0 1 2 3 4 5 6
//
//       1 1 2 2 2 3 3
//       1 5 2 3 4 0 6

// 5ms 71.43% 41.5MB 28.57%
// brute force, hash map
// O(N^2) O(N)
class Solution {
    public int countPairs(int[] nums, int k) {
        // {num, [idx, ...]}
        Map<Integer, List<Integer>> idxMap = new HashMap<>();
        for (int i = 0; i < nums.length; ++i) {
            idxMap.computeIfAbsent(nums[i], key -> new ArrayList<>()).add(i);
        }
        int cnt = 0;
        // System.out.println(idxMap);
        for (List<Integer> idxs : idxMap.values()) {
            for (int i = 1; i < idxs.size(); ++i) {
                for (int j = 0; j < i; ++j) {
                    if (idxs.get(i) * idxs.get(j) % k == 0) {
                        ++cnt;
                    }
                }
            }
        }
        return cnt;
    }
}

// 4ms 100.00% 43.5MB 14.29%
// brute force
// O(N^2) O(1)
class Solution {
    public int countPairs(int[] nums, int k) {
        int cnt = 0;
        for (int i = 1; i < nums.length; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] == nums[i] && (i*j) % k == 0) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
