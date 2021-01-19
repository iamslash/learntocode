// Copyright (C) 2021 by iamslash

import java.util.*;

// // Time Limit Exceeded
// // brute force
// // O(N^2) O(1)
// class Solution {
// 	private boolean isPowerOf2(int num) {
// 		return Integer.bitCount(num) == 1;
// 	}
// 	public int countPairs(int[] deliciousness) {
		
// 		int ans = 0, n = deliciousness.length;
// 		for (int i = 0; i < n; ++i) {
// 			for (int j = i+1; j < n; ++j) {
// 				if (isPowerOf2(deliciousness[i] + deliciousness[j])) {
// 					ans++;
// 				}
// 			}
// 		}
// 		return ans;
// 	}
// }

// 154ms 63.87% 49.8MB 71.16%
// hash map
// O(N) O(N)
class Solution {
	private final int MOD = 1000000007;
	public int countPairs(int[] deliciousness) {		
		long ans = 0, n = deliciousness.length;
		Map<Integer, Integer> cntMap = new HashMap<>();
		for (int num : deliciousness) {
			int power = 1;
			for (int i = 0; i < 22; ++i) {
				int opp = power - num;
				if (cntMap.containsKey(opp)) {
					ans = (ans + cntMap.get(opp)) % MOD;
				}				
				power <<= 1;
			}
			cntMap.put(num, cntMap.getOrDefault(num, 0) + 1);
		}
		return (int)ans;
	}
}

