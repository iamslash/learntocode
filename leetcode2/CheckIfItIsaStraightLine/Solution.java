// Copyright (C) 2020 by iamslash

import java.util.Arrays;

// 3ms 10.69% 39MB 100.00%
// slope
// O(NlgN) O(1)
class Solution {
	public boolean checkStraightLine(int[][] P) {
		Arrays.sort(P, (a, b) -> {
				if (a[0] == b[0])
					return a[1] - b[1];
				return a[0] - b[0];
			});
		int slopeA = 0;
		if (P[1][0] - P[0][0] > 0)
			slopeA = (P[1][1] - P[0][1])/(P[1][0]-P[0][0]);			
		for (int i = 1; i < P.length; ++i) {
			int slopeB = 0;
            if (P[i][0] - P[i-1][0] > 0)
    			slopeB = (P[i][1] - P[i-1][1])/(P[i][0]-P[i-1][0]);			
			if (slopeA != slopeB)
				return false;
		}
		return true;
	}
}
 
