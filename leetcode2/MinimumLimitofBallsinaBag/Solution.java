// Copyright (C) 2021 by iamslash

//   op: 2
// nums: 9
//    q: 6 3
//       3 3 3 

//   op: 4
// nums: 2 4 8 2
//    q: 2 2 4 8
//       2 2 4 4 4
//       2 2 4 4 4

// 30ms 100.00% 51.2MB 100.00%
// binary search
// O(Nlg10^9) O(1)
class Solution {
	public int minimumSize(int[] nums, int maxOperations) {
		int l = 1, r = 1_000_000_000;
		while (l < r) {
			int m = l + (r-l)/2;
			int cnt = 0;
			for (int num : nums) {
				cnt += (num - 1) / m;
			}
			if (cnt > maxOperations) {
				l = m + 1;
			} else {
				r = m;
			}
		}
		return l;
	}
}
