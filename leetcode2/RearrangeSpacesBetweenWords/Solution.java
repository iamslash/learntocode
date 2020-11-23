// Copyright (C) 2020 by iamslash

import java.util.*;

// 5ms 33.33% 37.7MB 66.67%
// string
// O(N) O(N)
class Solution {
	public String reorderSpaces(String s) {
		String[] words = s.trim().split("\\s+");
		int space = (int)s.chars().filter(c -> c == ' ').count();
		int n = words.length;
		if (n == 1) {
			return words[0] + " ".repeat(space);
		}
		return String.join(" ".repeat(space/(n-1)), words) + " ".repeat(space % (n-1));
	}
}
