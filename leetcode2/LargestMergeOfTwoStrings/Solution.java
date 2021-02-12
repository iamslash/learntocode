// Copyright (C) 2021 by iamslash

import java.util.*;

// 56ms 69.09% 39.4MB 81.75%
// two pointers
// O(N^2) O(N)
class Solution {
	public String largestMerge(String word1, String word2) {
		int n = word1.length() + word2.length(), i = 0, j = 0;
		StringBuilder sb = new StringBuilder();
		while (i + j < n) {
			String a = word1.substring(i);
			String b = word2.substring(j);
			if (a.compareTo(b) > 0) {
				sb.append(word1.charAt(i++));
			} else {
				sb.append(word2.charAt(j++));
			}
		}
		return sb.toString();
	}
}
