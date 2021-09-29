// Copyright (C) 2021 by iamslash

import java.util.*;

//               i
// nums: 0 4 1 2 
//             
// stck: 0 2 3 
//    j: 1
//    k: 0
//         
//  ans: 4 0 0 0

// monotonic stack
// O(N) O(N)
class Solution {
    public int[] findMaximums(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        Stack<Integer> stck = new Stack<>();
        for (int i = 0; i <= n; ++i) {
            while (!stck.empty() && (i == n || nums[stck.peek()] >= nums[i])) {
                int j = stck.pop();
                int k = i - 1;
                if (!stck.empty()) {
                    k -= stck.peek() + 1;
                }
                ans[k] = Math.max(ans[k], nums[j]);
            }
            stck.push(i);
        }
        for (int i = n-1; i > 0; --i) {
            ans[i-1] = Math.max(ans[i-1], ans[i]);
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
