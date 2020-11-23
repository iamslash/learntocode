// Copyright (C) 2020 by iamslash

import java.util.*;

// 2ms 94.10% 39.1MB 8.04%
// linear traversal
// O(N) O(N)
class Solution {
	public String addStrings(String a, String b) {
		StringBuilder sb = new StringBuilder();
		int carry = 0;
		for (int i = a.length() - 1, j = b.length() - 1;
				 i >= 0 || j >= 0 || carry == 1;
				 --i, --j) {
			int x = i < 0 ? 0 : a.charAt(i) - '0';
			int y = j < 0 ? 0 : b.charAt(j) - '0';
			sb.append((x + y + carry) % 10);
			carry = (x + y + carry) / 10;
		}
		return sb.reverse().toString();
	}
}
