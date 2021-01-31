// Copyright (C) 2021 by iamslash

import java.util.*;

// 63ms 12.50% 46.7MB 12.50%
// hash map
// O(N) O(N)
class Solution {
	private int getSumDigit(int n) {
		int sum = 0;
		while (n > 0) {
			sum += n % 10;
			n /= 10;
		}
		return sum;
	}
	public int countBalls(int lo, int hi) {
		Map<Integer, Integer> freqMap = new HashMap<>();
		for (int i = lo; i < hi; ++i) {
			int num = getSumDigit(i);
			freqMap.put(num, freqMap.getOrDefault(num, 0) + 1);
		}
		return Collections.max(freqMap.values());
	}
}

// 24ms 37.50% 37.3MB 25.00%
// hash map
class solution {
	private int getSumDigit(int n) {
		int sum = 0;
		while (n > 0) {
			sum += n % 10;
			n /= 10;
		}
		return sum;
	}
	public int countBalls(int lo, int hi) {
		int[] freqs = new int[50];
		int maxFreq = 0;
		for (int i = lo; i <= hi; ++i) {
			int num = getSumDigit(i);
			maxFreq = Math.max(maxFreq, ++freqs[num]);
		}
		return maxFreq;
	}
}
