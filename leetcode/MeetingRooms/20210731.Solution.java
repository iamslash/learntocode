// Copyright (C) 2020 by iamslash

import java.util.*;

// sort
// O(NlgN) O(1)
class Solution {
	public boolean canAttendMeetings(int[][] I) {
		if (I == null)
			return false;
		Arrays.sort(I, (int[] a, int[] b) -> {
				if (a[1] == b[1])
					return a[0] - b[0];
				return a[1] - b[1];
			});
		for (int i = 1; i < I.length; ++i) {
			if (I[i-1][1] > I[i][0])
				return false;
		}
		return true;
	}
}
