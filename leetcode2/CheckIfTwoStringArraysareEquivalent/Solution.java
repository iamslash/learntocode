// Copyright (C) 2020 by iamslash

import java.util.*;

// 1ms 42.86% 36.9MB 100.00%
// brute force
// O(N) O(N)
class Solution {
	public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
		return String.join("", word1).equals(String.join("", word2));
	}
}
