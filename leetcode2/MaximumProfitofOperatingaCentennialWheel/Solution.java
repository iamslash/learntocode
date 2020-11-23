// Copyright (C) 2020 by iamslash

// 10ms 100.00% 49MB 100.00%
// greedy algorithm
// O(N) O(1)
class Solution {
	public int minOperationsMaxProfit(int[] customers, int bcost, int rcost) {
		int run = 0, maxRun = 1;
		int prof = 0, maxProf = 0;
		int sum = 0, i = 0;
		while (sum > 0 || i < customers.length) {
			if (i < customers.length)
				sum += customers[i++];
			int boarded = Math.min(4, sum);
			sum -= boarded;
			prof = prof + boarded * bcost - rcost;
			run++;
			if (prof > maxProf) {
				maxProf = prof;
				maxRun = run;
			}
		}
		if (maxProf > 0)
			return maxRun;
		return -1;				 
	}
}
