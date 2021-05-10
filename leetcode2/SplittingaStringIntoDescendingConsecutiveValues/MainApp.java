// Copyright (C) 2021 by iamslash

import java.util.*;

//    i
// s: 0090089
//
//    .   .    .    .
// s: 3529855956507776

// 0ms 100.00% 37.5MB 62.96%
// backtracking
// O(2^N) O(N)
class Solution {
	private boolean dfs(String s, long prev) {
		long curr = 0;
		int n = s.length();
		for (int i = 0; i < n; ++i) {
			curr = curr * 10 + s.charAt(i) - '0';
			if (curr >= 10_000_000_000L) {
				return false;
			}
			if (prev < 0) {
				if (dfs(s.substring(i+1), curr)) {
					return true;
				}
				continue;
			}
			if (curr == prev - 1) {
				if (i == n - 1) {
					return true;
				}
				if (dfs(s.substring(i+1), curr)) {
					return true;
				}
			}
		}
		return false;
	}
	public boolean splitString(String s) {
		return dfs(s, -1);
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
