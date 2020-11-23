// Copyright (C) 2020 by iamslash

import java.util.Arrays;
import java.util.Stack;

// 43ms 34.56% 48.9MB 9.09%
// TSP, bit manipulation
// O(N^2 * 2^N) O(N^2)
class Solution {	
	private int dist(String a, String b) {
		for (int i = 1; i < a.length(); ++i) {
			if (b.startsWith(a.substring(i)))
				return b.length() - a.length() + i;
		}
		return b.length();
	}
	public String shortestSuperstring(String[] A) {
		int n = A.length;
        if (n == 1)
            return A[0];
		int[][] G = new int[n][n];
		for (int u = 0; u < n; ++u) {
			for (int v = 0; v < n; ++v) {
				G[u][v] = dist(A[u], A[v]);
				G[v][u] = dist(A[v], A[u]);
			}
		}
		int[][] C = new int[1 << n][n];
		int[][] P = new int[1 << n][n];
		int last = -1, min = Integer.MAX_VALUE;

		// dynamic programming
		for (int s = 1; s < (1 << n); ++s) {
			Arrays.fill(C[s], Integer.MAX_VALUE);
			for (int j = 0; j < n; ++j) {
				if ((s & (1 << j)) > 0) {
					int t = s - (1 << j);
					if (t == 0) {
						C[s][j] = A[j].length();
						continue;
					}
					for (int k = 0; k < n; ++k) {
						if (C[t][k] < Integer.MAX_VALUE &&
								C[t][k] + G[k][j] < C[s][j]) {
							C[s][j] = C[t][k] + G[k][j];
							P[s][j] = k;
						}
					}						
				}
				if (s == (1 << n) - 1 && C[s][j] < min) {
					min = C[s][j];
					last = j;
				}
			}
		}

		// build the stack
		StringBuilder sb = new StringBuilder();
		int tovisit = (1 << n) - 1;
		Stack<Integer> stck = new Stack<>();
		while (tovisit > 0) {
			stck.push(last);
			int t = tovisit;
			tovisit -= (1 << last);
			last = P[t][last];
		}

		// reconstruct the path 
		int u = stck.pop();
		sb.append(A[u]);
		while (stck.size() > 0) {
			int v = stck.pop();
			sb.append(A[v].substring(A[v].length() - G[u][v]));
			u = v;
		}
		return sb.toString();
	}
}
