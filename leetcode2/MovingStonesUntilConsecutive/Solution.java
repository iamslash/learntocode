// Copyright (C) 2020 by iamslash

import java.util.Arrays;

// 1ms 54.31% 36.9MB 6.06%
// math
// O(1) O(1)
class Solution {
	public int[] numMovesStones(int a, int b, int c) {
		int minMove = 0, maxMove = 0;
		int[] P = {a, b, c};
		Arrays.sort(P);
		if (P[2] - P[0] == 2)
			return new int[]{0 ,0};
		minMove = 2;
		if (Math.min(P[1] - P[0], P[2] - P[1]) <= 2)
			minMove = 1;
		maxMove = P[2] - P[0] - 2;
		return new int[]{minMove, maxMove};
	}
}
