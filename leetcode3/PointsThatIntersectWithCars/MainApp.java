// Copyright (C) 2023 by iamslash

import java.util.*;

//                 i
// nums: 1,5 3,6 4,7
//  ans:   5   6   7
// last:   5   6

//             i
// nums: 1,6 2,5 3,8 4,10
//  ans:   6
// last:   6

// 1 <= nums.length <= 100
// nums[i].length == 2
// 1 <= starti <= endi <= 100

// 5ms 44.74% 43.2MB 70.99%
// sort
// O(NlgN) O(1)
class Solution {
    public int numberOfPoints(List<List<Integer>> nums) {
        Collections.sort(nums, (a, b) -> a.get(0) == b.get(0) ? a.get(1) - b.get(1) : a.get(0) - b.get(0)); 
        int last = -1, ans = 0;
        for (List<Integer> car : nums) {
            int start = car.get(0), end = car.get(1);
            if (last < start) {
                ans += end - start + 1;
            } else if (last < end) {
                ans += end - last;
            }
            last = Math.max(last, end);
        }
        return ans;
    }
}


//         
// nums: 1,6 2,5 3,8 4,10
// evts: 1 2 3 4 5 6 7 8 9 10
//                          
//       1 1 1 1 1 1
//         1 1 1 1
//           1 1 1 1 1 1
//             1 1 1 1 1 1  1
//       


//         
// nums: 1,3 5,8 
// evts: 1 2 3 4 5 6 7 8 9 10
//       1 1 1
//               1 1 1 1

// 2ms 92.68% 43MB 97.10%
// line sweep
// O(1) O(1)
class Solution {
    public int numberOfPoints(List<List<Integer>> nums) {
        int[] evts = new int[101];
        for (List<Integer> car : nums) {
            int start = car.get(0), end = car.get(1);
            for (int i = start; i <= end; ++i) {
                evts[i]++;
            }
        }
        int ans = 0;
        for (int i = 1; i <= 100; ++i) {
            if (evts[i] > 0) {
                ans++;
            }
        }
        return ans;
    }
}
