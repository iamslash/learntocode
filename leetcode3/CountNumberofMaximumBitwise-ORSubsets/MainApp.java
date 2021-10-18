// Copyright (C) 2021 by iamslash

//           a
//   nums: 3 1
//         
//  maxBm: 3
//         b
//      C: 0 1 2 3 
//         1 1 0 2

// 84ms 72.73% 45.5MB 72.73%
// iterative dynamic programming
// O(NM) O(M)
// M: max(nums)
class Solution {
    public int countMaxOrSubsets(int[] nums) {
        int[] C = new int[1000000];
        C[0] = 1; // seed
        int maxBm = 0;
        for (int num : nums) {
            for (int bm = maxBm; bm >= 0; --bm) {
                C[num | bm] += C[bm];
            }
            maxBm |= num;
        }
        return C[maxBm];
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
