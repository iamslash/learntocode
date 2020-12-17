// Copyright (C) 2020 by iamslash

import java.util.*;

// A: 1 2 3 4    ans   minNum
//
//    2 2 4 6    4     2
//    2 2 3 4    4     2
//    2 2 2 3    2     2
//    2 2 2 
//    

// 130ms 41.55% 115.1MB 6.34%
// priority queue
// O(NlgN) O(N)
class Solution {
	public int minimumDeviation(int[] A) {
		Queue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
		int ans = Integer.MAX_VALUE, minNum = Integer.MAX_VALUE;
		for (int a : A) {
			if (a % 2 > 0)
				a *= 2;
			pq.add(a);
			minNum = Math.min(minNum, a);
		}
		while (true) {
			int num = pq.poll();
			ans = Math.min(ans, num - minNum);
			if (num % 2 > 0)
				break;
			num /= 2;
			minNum = Math.min(minNum, num);
			pq.add(num);
		}
		return ans;
	}
}
