// Copyright (C) 2021 by iamslash

import java.util.*;

//           .....
//   nums: 1 2 3 2 2 1 3
//               i
// cntMap: 1 2 3
//         1 1 1
//    ans: 3 2 2

// 78ms 100.00% 58MB 100.00%
// hash map
// O(N) O(N)
class Solution {
	public int[] distinctNumbers(int[] nums, int k) {
		int n = nums.length;
		if (n-k+1 <= 0) {
			return new int[0];
		}
		int[] ans = new int[n-k+1];
		Map<Integer, Integer> cntMap = new HashMap<>();
		for (int i = 0; i < n; ++i) {
			int num = nums[i];
			cntMap.put(num, cntMap.getOrDefault(num, 0)+1);
			if (i >= k) {
				int numToDel = nums[i-k];
				cntMap.put(numToDel, cntMap.get(numToDel) - 1);
				if (cntMap.get(numToDel) <= 0) {
					cntMap.remove(numToDel);
				}
			}
			if (i >= k-1) {
				ans[i-k+1] = cntMap.size();
			}
		}
		return ans;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
