// Copyright (C) 2021 by iamslash

import java.util.*;

//               i
// nums: 1 2 3 2
//       j
//       k
// stck:    
//  ans: 14
//
// nums: 2 3 3 1 2
//           _____
// nums: 3 1 5 6 4 2
//

// 41ms 80.15% 54.6MB 53.03%
// mono stack
// O(N) O(N)
class Solution {
	public int maxSumMinProduct(int[] nums) {
		final int MOD = 1000000007;
		int n = nums.length;
		Stack<Integer> stck = new Stack<>();
		long ps[] = new long[n+1], ans = 0;
		for (int i = 0; i < n; ++i) {
			ps[i+1] = ps[i] + nums[i];
		}
		for (int i = 0; i <= n; ++i) {
			while (!stck.empty() &&
						 (i == n || nums[stck.peek()] > nums[i])) {
				int j = stck.pop();
				int k = 0;
				if (!stck.empty()) {
					k = stck.peek() + 1;
				}
				long sum = ps[i] - ps[k];
				ans = Math.max(ans, sum * nums[j]);
			}
			stck.push(i);
		}
		return (int)(ans % MOD);
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
