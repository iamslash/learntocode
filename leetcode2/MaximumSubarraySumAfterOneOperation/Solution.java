// Copyright (C) 2021 by iamslash

import java.util.*;

//    nums: 2 -1 -4 -3
// maxNoOp: 2 
// maxOnOp: 4
//  glbMax: 4

// // 21ms 44.52% 53.5MB 41.29%
// // iterative dynamic programming
// // O(N) O(N)
// class Solution {
// 	public int maxSumAfterOperation(int[] nums) {
// 		int n = nums.length;
// 		// C[i][0]: max sum of zero operation
// 		// C[i][1]: max sum of one operatied nums[i]		
// 		int[][] C = new int[n][2];
// 		C[0][0] = nums[0];
// 		C[0][1] = nums[0] * nums[0];
// 		int ans = C[0][1];
// 		for (int i = 1; i < n; ++i) {
// 			C[i][0] = Math.max(C[i-1][0], 0) + nums[i];
// 			C[i][1] = Math.max(
// 					Math.max(0, C[i-1][0]) + nums[i] * nums[i],
// 					C[i-1][1] + nums[i]);
// 			ans = Math.max(ans, C[i][1]);
// 		}
// 		return ans;
// 	}
// }

// 5ms 90.32% 53.5MB 46.45%
// iterative dynamic programming
// O(N) O(1)
class Solution {
	public int maxSumAfterOperation(int[] nums) {
		int n = nums.length;
		int curMaxNoOp = nums[0];
		int curMaxOnOp = nums[0] * nums[0]; 
		int glbMaxOnOp = curMaxOnOp;;
		for (int i = 1; i < n; ++i) {
			int prvMaxNoOp = curMaxNoOp;
			int prvMaxOnOp = curMaxOnOp;
			curMaxNoOp = Math.max(prvMaxNoOp, 0) + nums[i];
			curMaxOnOp = Math.max(
					Math.max(prvMaxNoOp, 0) + nums[i] * nums[i],
					prvMaxOnOp + nums[i]);
			glbMaxOnOp = Math.max(glbMaxOnOp, curMaxOnOp);
		}
		return glbMaxOnOp;
	}
}

// 3ms 100.00% 52.3MB 78.06%
// iterative dynamic programming
// O(N) O(1)
class Solution {
	public int maxSumAfterOperation(int[] nums) {
		int ans = 0, onOps = 0, noOps = 0;
		for (int num : nums) {
			onOps = Math.max(onOps + num, noOps + num*num);
			noOps = Math.max(noOps + num, 0);
			ans   = Math.max(ans, onOps);
		}
		return ans;
	}
}
