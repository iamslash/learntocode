// Copyright (C) 2020 by iamslash

// 1 2 3 4 5
// 1 2     5 7   9
// 1   3 4 5   8
import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;

// // 8ms 13.26% 40.4MB 100.00%
// // hash map
// // O(N) O(N)
// class Solution {
// 	public List<Integer> arraysIntersection(int[] A, int[] B, int[] C) {
// 		Map<Integer, Integer> cnts = new HashMap<>();
// 		for (int a : A)
// 			cnts.put(a, cnts.getOrDefault(a, 0) + 1);
// 		for (int a : B)
// 			cnts.put(a, cnts.getOrDefault(a, 0) + 1);
// 		for (int a : C)
// 			cnts.put(a, cnts.getOrDefault(a, 0) + 1);
// 		List<Integer> ans = new ArrayList();
// 		cnts.forEach((k, v) -> {
// 				if (v >= 3)
// 					ans.add(k);
// 					});
// 		return ans;
// 	}
// }

// 1ms 100.00% 40.1MB 100.00%
// two pointers
// O(N) O(Nx)
class Solution {
	public List<Integer> arraysIntersection(int[] A, int[] B, int[] C) {
		List<Integer> ans = new ArrayList<>();
		int i = 0, j = 0, k = 0;
		while (i < A.length && j < B.length && k < C.length) {
			if (A[i] == B[j] && B[j] == C[k]) {
				ans.add(A[i]);
				i++;
				j++;
				k++;
			} else if (A[i] < B[j]) {
				i++;
			} else if (B[j] < C[k]) {
				j++;
			}	else {
				k++;
			}
		}
		return ans;
	}
}
