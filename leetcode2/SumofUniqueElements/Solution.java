// Copyright (C) 2021 by iamslash

import java.util.*;

// hash map
// O(N) O(N)
// 1ms 50.00% 36.7MB 100.00%
class Solution {
	public int sumOfUnique(int[] nums) {
		int sum = 0;
		Map<Integer, Integer> freqMap = new HashMap<>();
		for (int i = 0; i < nums.length; ++i) {
			freqMap.put(nums[i], freqMap.getOrDefault(nums[i], 0) + 1);
			if (freqMap.get(nums[i]) == 1) {
				sum += nums[i];
			} else if (freqMap.get(nums[i]) == 2) {
				sum -= nums[i];
			}
		}
		return sum;
	}
}

// hash map
// O(N) O(1)
// 0ms 100.005 36.7MB 100.00%
class Solution {
	public int sumOfUnique(int[] nums) {
		int[] freqs = new int[101];
		for (int i : nums) {
			freqs[i]++;			
		}
		int sum = 0;
		for (int i = 1; i <= 100; ++i) {
			if (freqs[i] == 1) {
				sum += i;
			}
		}
		return sum;
	}
}
