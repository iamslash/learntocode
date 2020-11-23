// Copyright (C) 2020 by iamslash

import java.util.Arrays;

// 1ms 21.10% 37.2MB 50.00%
// math
// O(N) O(1)
// class Solution {
// 	public int sumOfDigits(int[] A) {
// 		int num = Arrays.stream(A).min().getAsInt();
// 		int ans = 0;
// 		while (num > 0) {
// 			ans += num % 10;
// 			num /= 10;
// 		}
// 		return (ans & 1) == 1 ? 0 : 1;
// 	}
// }

// 0ms 100.00% 36.8MB 50.00%
// math
// O(N) O(1)
class Solution {
	public int sumOfDigits(int[] A) {
		int num = Integer.MAX_VALUE;
		for (int a : A)
			if (a < num)
				num = a;
		int ans = 0;
		while (num > 0) {
			ans += num % 10;
			num /= 10;
		}
		return (ans & 1) == 1 ? 0 : 1;
	}
}
