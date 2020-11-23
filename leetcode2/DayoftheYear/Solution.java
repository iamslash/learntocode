// Copyright (C) 2020 by iamslash

// 2ms 48.69% 37.5MB 100.00%
// math
// O(N) O(1)
class Solution {
	private static final int[] days = {31, 28, 31, 30, 31,
																		 30, 31, 31, 30, 31,
																		 30, 31};	
	public int dayOfYear(String date) {
		String[] DD = date.split("-");
		int Y = Integer.valueOf(DD[0]);
		int M = Integer.valueOf(DD[1]);
		int D = Integer.valueOf(DD[2]);
		int ans = 0;
		for (int m = 0; m < M-1; ++m) {
			if (m == 1 && (Y % 4 == 0 && (Y % 100 != 0 || Y % 400 == 0))) {
				ans += 29;
			} else {
				ans += days[m];
			}
		}
		return ans + D;
	}
}
