// Copyright (C) 2021 by iamslash

import java.util.*;

// s: heeellooo
//          i
//    hello
//        j
//    hi
//    helo

// 1ms 97.95% 37.5MB 70.91%
// four pointers
// O(N) O(1)
class Solution {
	private boolean stretchy(String s, String t) {
		int n = s.length(), m = t.length();
		int i1 = 0, j1 = 0;
		for (int i2 = 0, j2 = 0; i1 < n && j1 < m; i1 = i2, j1 = j2) {
			if (s.charAt(i1) != t.charAt(j1)) {
				return false;
			}
			while (i2 < n && s.charAt(i2) == s.charAt(i1)) {
				i2++;
			}
			while (j2 < m && t.charAt(j2) == t.charAt(j1)) {
				j2++;
			}
			if (i2 - i1 != j2 - j1 &&
					i2 - i1 < Math.max(3, j2 - j1)) {
				return false;
			}
		}
		return i1 == n && j1 == m;
	}
	public int expressiveWords(String s, String[] words) {
		int ans = 0;
		for (String word : words) {
			if (stretchy(s, word)) {
				ans++;
			}
		}
		return ans;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
