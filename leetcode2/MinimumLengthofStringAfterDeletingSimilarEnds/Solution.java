// Copyright (C) 2021 by iamslash

import java.util.*;


//     i 
// c c
//   j

// 3ms 92.79% 40MB 56.80%
// two pointers
// O(N) O(1)
class Solution {
	public int minimumLength(String s) {
		int n = s.length(), i = 0, j = n-1;
		while (i < j && s.charAt(i) == s.charAt(j)) {
			Character c = s.charAt(i);
			while (i <= j && s.charAt(i) == c) {
				++i;
			}
			while (i <= j && s.charAt(j) == c) {
				--j;
			}
			if (i > j) {
				return 0;
			}
		}
  	return j - i + 1;    
	}
}
