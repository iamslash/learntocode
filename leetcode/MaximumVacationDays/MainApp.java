// Copyright (C) 2021 by iamslash

import java.util.*;

// 68ms 23.71% 40.8MB 86.18%
// recursive dynamic programming
// O(NK) O(NK)
// N: the count of city
// K: weeks
class Solution {
	private int dfs(int[][] F, int[][] D, int[][] C,
									int u, int week) {
		int ncity = D.length, nweek = D[0].length;
		// base
		if (week >= nweek) {
			return 0;
		}
		// memo
		if (C[u][week] >= 0) {
			return C[u][week];
		}
		// recursion
		int maxvac = 0;
		for (int v = 0; v < ncity; ++v) {
			if (F[u][v] == 1 || u == v) {
				maxvac = Math.max(
						maxvac,
						D[v][week] + dfs(F, D, C, v, week+1));
			}
		}
		return C[u][week] = maxvac;
	}
	public int maxVacationDays(int[][] F, int[][] D) {
		// C[i][j]: max vacations of when start
		//          from i-th city, at j-th week
		int[][] C = new int[D.length][D[0].length];
		for (int i = 0; i < C.length; ++i) {
			Arrays.fill(C[i], -1);
		}
		return dfs(F, D, C, 0, 0);
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
