// Copyright (C) 2020 by iamslash

import java.util.List;
import java.util.ArrayList;

// 0ms 100.00% 37.8MB 100.00%
// String
// O(T) O(T)
class Solution {
	public String[] findOcurrences(String text, String first, String second) {
		List<String> ans = new ArrayList<>();
		String[] tokens = text.split(" ");
		for (int i = 2; i < tokens.length; ++i) {
			if (tokens[i-2].compareTo(first) == 0 &&
					tokens[i-1].compareTo(second) == 0)
				ans.add(tokens[i]);
		}
		return ans.toArray(new String[ans.size()]);
	}
}
