// Copyright (C) 2022 by iamslash

import java.util.*;

// nums: 1 2 3 4 5
//       1 2
//         2 3
//           3 4
//             4 5
//       1   3
//         2   4
//           3   5
//       1     4
//         2     5
//       1       5

// nums: 4 1 2 3
//       4 1       3
//       4   2     3
//       4     3   3
//         1 2     1
//         1   3   2
//           2 3   1

// nums: 3 1 2
//

// 24ms 49.97% 45.3MB 16.23%
// brute force
// O(N^2) O(1)
class Solution {
    public long subArrayRanges(int[] nums) {
        long sum = 0, n = nums.length;
        for (int i = 0; i < n; ++i) {
            int max = nums[i], min = nums[i];
            for (int j = i+1; j < n; ++j) {
                max = Math.max(max, nums[j]);
                min = Math.min(min, nums[j]);
                sum += (max - min);
                // System.out.printf("i: %d, j: %d, max: %d, min: %d\n", i, j, max, min);
            }
        }
        return sum;
    }
}

//               i
// nums: 3 2 1 4
//           j      
//      k     
// stck:  
//

// 23ms 51.99% 46.6MB 12.01%
// mono stack
// O(N) O(N)
class Solution {
    public long subArrayRanges(int[] nums) {
        int n = nums.length, j, k;
        long sum = 0;
        Stack<Integer> stck = new Stack<>();
        for (int i = 0; i <= n; ++i) {
            while (!stck.isEmpty() &&
                   nums[stck.peek()] > (i == n ? Integer.MIN_VALUE : nums[i])) {
                j = stck.pop();
                k = stck.isEmpty() ? -1 : stck.peek();
                sum -= (long)nums[j] * (j - k) * (i - j);
            }
            stck.push(i);
        }
        stck.clear();
        for (int i = 0; i <= n; ++i) {
            while (!stck.isEmpty() &&
                   nums[stck.peek()] < (i == n ? Integer.MAX_VALUE : nums[i])) {
                j = stck.pop();
                k = stck.isEmpty() ? -1 : stck.peek();
                sum += (long)nums[j] * (j - k) * (i - j);
            }
            stck.push(i);
        }
        return sum;
    }
}

//         i
// nums: 4 1 2 3
//       l
//             r
//

// 3ms 99.76% 44.8MB 18.57%
// math
// O(N^2) O(1)
class Solution {
    public long subArrayRanges(int[] nums) {
        long sum = 0;
        int n = nums.length, l = -1, r = -1;
        for (int i = 0; i < n; ++i) {
            l = i-1; r = i+1;
            while (l >= 0 && nums[l] > nums[i]) {
                l--;
            }
            while (r < n && nums[r] >= nums[i]) {
                r++;
            }
            sum -= (i - l) * (r - i) * (long)(nums[i]);
            l = i-1; r = i+1;
            while (l >= 0 && nums[l] < nums[i]) {
                l--;
            }
            while (r < n && nums[r] <= nums[i]) {
                r++;
            }
            sum += (i - l) * (r - i) * (long)(nums[i]);
        }        
        return sum;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
