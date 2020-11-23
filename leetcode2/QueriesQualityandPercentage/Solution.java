// Copyright (C) 2020 by iamslash

import java.util.List;
import java.util.LinkedList;

// 12ms 52.84% 39.6MB 57.16%
// linked list
// O(N) O(N)
class Solution {
	public int[] processQueries(int[] Q, int m) {
		LinkedList<Integer> P = new LinkedList<>();
		for (int i = 0; i < m; ++i) {
			P.add(i+1);
		}
		int[] ans = new int[Q.length];
		for (int i = 0; i < Q.length; ++i) {
			int q = Q[i];
			int j = P.indexOf(q);
			ans[i] = j;
			P.remove(j);
			P.addFirst(q);					
		}
		return ans;
	}
}
