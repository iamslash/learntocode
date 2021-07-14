// Copyright (C) 2021 by iamslash

import java.util.*;

// 436ms 24.37% 160.2MB 7.87%
// partial sum
// O(N) O(N)
class Solution {
	public int[] minDifference(int[] nums, int[][] queries) {
		int[][] psCnt = new int[100001][101];
		int n = nums.length;
		int[] ans = new int[queries.length];
		for (int i = 0; i < n; ++i) {
			for (int a = 1; a <= 100; ++a) {
				psCnt[i+1][a] = psCnt[i][a];
				if (a == nums[i]) {
					psCnt[i+1][a] += 1;
				}
			}
		}
		for (int i = 0; i < queries.length; ++i) {
			int fr = queries[i][0];
			int to = queries[i][1];
			int prev = 0, delta = Integer.MAX_VALUE;
			for (int a = 1; a <= 100; ++a) {
				if (psCnt[to+1][a] - psCnt[fr][a] > 0) {
					delta = Math.min(delta, prev == 0 ? Integer.MAX_VALUE : a - prev);
					prev = a;
				}
			}
			ans[i] = delta == Integer.MAX_VALUE ? -1 : delta;
		}
		return ans;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
