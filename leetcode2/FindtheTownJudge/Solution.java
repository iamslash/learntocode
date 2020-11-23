// Copyright (C) 2020 by iamslash

import java.util.Arrays;

// indegree, outdegree
// O(N) O(N)
class Solution {
	public int findJudge(int N, int[][] T){
		int[] inDeg = new int[N];
		int[] ouDeg = new int[N];
		Arrays.fill(inDeg, 0);
		Arrays.fill(ouDeg, 0);
		for (int[] t : T) {
			ouDeg[t[0]-1]++;
			inDeg[t[1]-1]++;
		}
		for (int i = 0; i < N; ++i) {
			if (ouDeg[i] == 0 && inDeg[i] == N-1)
				return i+1;
		}
		return -1;
	}
}
