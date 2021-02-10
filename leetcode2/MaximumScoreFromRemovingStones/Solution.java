// Copyright (C) 2021 by iamslash

import java.util.*;

// 30ms 35.08% 59MB 18.35%
// recursion
// O(max(a,b,c))
class Solution {
	public int maximumScore(int a, int b, int c) {
		// recursion
		if (a > b) {
			return maximumScore(b, a, c);
		}
		if (b > c) {
			return maximumScore(a, c, b);
		}
    if (b == 0) {
      return 0;
    }
		return 1 + maximumScore(a, b-1, c-1);
	}
}
