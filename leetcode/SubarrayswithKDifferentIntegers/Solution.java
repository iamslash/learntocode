// Copyright (C) 2019 by iamslash

import java.util.*;

// hash map, sliding window
// O(N) O(N)
class Solution {
	private int cntWithMostK(int[] A, int K) {
    int n = A.length, ans = 0;
		Map<Integer, Integer> cnt = new HashMap<>();
		for (int i = 0, j = 0; j < n; ++j) {
			// inspect j
			if (cnt.getOrDefault(A[j], 0) == 0)
				--K;
			cnt.put(A[j], cnt.getOrDefault(A[j], 0) + 1);
			// inspect i
			while (K < 0) {
				cnt.put(A[i], cnt.get(A[i]) - 1);
				if (cnt.get(A[i]) == 0)
					++K;
				++i;
			}
			// update ans
			ans += j - i + 1;
		}
		return ans;
	}
  public int subarraysWithKDistinct(int[] A, int K) {
		return cntWithMostK(A, K) - cntWithMostK(A, K-1);
  }
  public static void main(String[] args) {
		int[] A = {1, 2, 1, 2, 3};
		int K = 2;

		Solution sln = new Solution();
		System.out.println(sln.subarraysWithKDistinct(A, K));
  }
}
