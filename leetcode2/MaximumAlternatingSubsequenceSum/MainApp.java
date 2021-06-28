// Copyright (C) 2021 by iamslash

import java.util.*;

//                i
//    nums: 4 2 5 3
// sumEven: 4 4 7 7
//  sumOdd: 0 2 2 4

// 4ms 100.00% 48.3MB 100.00%
// iterative dynamic programming
// O(N) O(1)
class Solution {
	public long maxAlternatingSum(int[] nums) {
		long sumOdd = 0, sumEven = 0;
		for (int num : nums) {
			sumEven = Math.max(sumEven, sumOdd+num);
			sumOdd = sumEven - num;
		}
		return sumEven;
	}
}

// 64ms 50.00% 79.1MB 50.00%
// recursive dynamic programming
// O(N^2) O(N)
class Solution {
	private long dfs(int[] nums, long C[][], int i, int ord) {
		// base
		if (i >= nums.length) {
			return 0;
		}
		// memo
		if (C[ord][i] >= 0) {
			return C[ord][i];
		}
		// recursion
		long sum = ord == 0 ? nums[i] : -nums[i];
		return C[ord][i] = Math.max(sum + dfs(nums, C, i+1, ord^1),
																dfs(nums, C, i+1, ord));
	}
	public long maxAlternatingSum(int[] nums) {
		long C[][] = new long[2][100001];
		for (int i = 0; i < 2; ++i) {
			Arrays.fill(C[i], -1);
		}
		return dfs(nums, C, 0, 0);
	}
}

// 2ms 100.00% 48MB 100.00%
class Solution {
	public long maxAlternatingSum(int[] nums) {
		long sum = nums[0];
		for (int i = 1; i < nums.length; ++i) {
			sum += Math.max(nums[i] - nums[i-1], 0);
		}
		return sum;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
