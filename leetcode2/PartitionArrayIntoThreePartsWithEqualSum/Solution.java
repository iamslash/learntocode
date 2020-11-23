// Copyright (C) 2020 by iamslash

// 1ms 100.00% 46.MB 100.00%
// math
// O(N) O(1)
class Solution {
	public boolean canThreePartsEqualSum(int[] A) {
		int sum = 0;		
		for (int a : A)
			sum += a;
		if (sum % 3 != 0)
			return false;
        sum /= 3;
		int cnt = 0;
		for (int i = 0, cum = 0; i < A.length; ++i) {
			cum += A[i];
			if (cum == sum) {
				cnt++;
				cum = 0;
			}
		}
		return cnt >= 3;
	}
}

