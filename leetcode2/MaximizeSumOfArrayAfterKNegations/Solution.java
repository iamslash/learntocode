// Copyright (C) 2020 by iamslash

import java.util.Queue;
import java.util.PriorityQueue;

// // 5ms 30.70% 39.2MB 11.76%
// // priority queue
// // O(NlgN) O(N)
// class Solution {
// 	public int largestSumAfterKNegations(int[] A, int K) {
// 		Queue<Integer> pq = new PriorityQueue<>();
// 		for (int a : A) {
// 			pq.add(a);
// 		}
// 		while (K-- > 0) {
// 			int f = pq.poll();
// 			pq.add(-f);
// 			if (pq.peek() > 0 && K % 2 == 0)
// 				break;
// 		}
// 		int ans = 0;
// 		while (pq.size() > 0) {
// 			ans += pq.poll();
// 		}
// 		return ans;
// 	}
// }

//  A: 4 3 -1 2 5
//  K: 0
//  A: 4 3 1 2 5
//  K: 3

// 1ms 99.84% 38.8% 11.76%
// sort
// O(NlgN) O(1)
class Solution {
	public int largestSumAfterKNegations(int[] A, int K) {
		Arrays.sort(A);
		for (int i = 0; i < A.length && A[i] < 0 && K > 0; ++i, --K) {
			A[i] = -A[i];
		}
		int sum = 0, min = Integer.MAX_VALUE;
		for (int a : A) {
			sum += a;
			min = Math.min(min, a);
		}
		return K % 2 == 0 ? sum : sum - min - min;
	}
}
