// Copyright (C) 2020 by iamslash

import java.util.Arrays;

// 1ms 97.51% 37.6MB 100.00%
// exhaustive search
// O(4^3) O(1)
class Solution {
	public String largestTimeFromDigits(int[] A) {
		String ans = "";
		for (int i = 0; i < 4; i++) {
			if (A[i] > 2)
				continue;
			for (int j = 0; j < 4; j++) {
				if (j == i || (A[i] == 2 && A[j] > 3))
					continue;
				for (int k = 0; k < 4; k++) {
					if (k == i || k == j || A[k] > 5)
						continue;
					int l = 6 - i - j - k;
					StringBuilder sb = new StringBuilder();
					sb
							.append(A[i])
							.append(A[j])
                            .append(":")
							.append(A[k])
							.append(A[l]);
					String combi = sb.toString();
					if (ans.compareTo(combi) < 0)
						ans = combi;
					 
				}
			}
		}
		return ans;
	}
}
