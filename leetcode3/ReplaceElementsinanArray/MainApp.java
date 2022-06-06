// Copyright (C) 2022 by iamslash

import java.util.*;

// nums: 3 2 7 1
//  ops: 1,3 4,7 6,1
//                 i
//  map: 1 2 4 6 3 7
//       3 1 2 3 0 2

// 83ms 16.67% 181.3MB 16.67%
// hash map
// O(N) O(N)
class Solution {
    public int[] arrayChange(int[] nums, int[][] operations) {
        Map<Integer, Integer> num2idxMap = new HashMap<>();
        for (int i = 0; i < nums.length; ++i) {
            num2idxMap.put(nums[i], i);
        }        
        for (int[] op : operations) {
            int idx = num2idxMap.get(op[0]);
            nums[idx] = op[1];
            num2idxMap.put(op[1], idx);
        }
        return nums;
    }
}

// 119ms 16.67% 282.7MB 16.67%
// hash map
// O(N) O(N)
class Solution {
    public int[] arrayChange(int[] nums, int[][] ops) {
        // {num : idx}
        int[] C = new int[1_000_001];
        for (int i = 0; i < nums.length; ++i) {
            C[nums[i]] = i;
        }
        for (int[] op : ops) {
            int idx = C[op[0]]; 
            nums[idx] = op[1];
            C[op[1]] = idx; 
        }
        return nums;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
