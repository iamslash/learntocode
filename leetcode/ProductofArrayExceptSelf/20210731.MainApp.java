// Copyright (C) 2021 by iamslash

// 3ms 16.02% 57MB 9.18%
// forward and backward
// O(N) O(N)
class Solution {
	public int[] productExceptSelf(int[] nums) {
		int[] leftProd = new int[nums.length];
		int[] rightProd = new int[nums.length];
		leftProd[0] = 1;
		rightProd[nums.length-1] = 1;
		int[] ans = new int[nums.length];
		for (int i = 1; i < nums.length; ++i) {
			leftProd[i] = nums[i-1] * leftProd[i-1];
		}
		for (int i = nums.length-2; i >= 0; --i) {
			rightProd[i] = nums[i+1] * rightProd[i+1];
		}
		for (int i = 0; i < nums.length; ++i) {
			ans[i] = leftProd[i] * rightProd[i];
		}
		return ans;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
