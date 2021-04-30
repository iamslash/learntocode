// Copyright (C) 2021 by iamslash

import java.util.*;
//      aeiou
//  bm: 20020
// ans: 13

//                          i
//   s: aeiaaioaaaaeiiiiouuuooaauuaeiu
// len: 1
// cnt: 1
// ans: 13

// 18ms 85.06% 45.2MB 93.00%
// longest non-decreasing substring
// O(N) O(1)
class Solution {
	public int longestBeautifulSubstring(String s) {
		int len = 1, cnt = 1, ans = 0, n = s.length();
		for (int i = 1; i < n; ++i) {
			if (s.charAt(i-1) == s.charAt(i)) {
				++len;
			} else if (s.charAt(i-1) < s.charAt(i)) {
				++len;
				++cnt;
			} else {
				cnt = 1;
				len = 1;
			}
			if (cnt == 5) {
				ans = Math.max(ans, len);
			}
		}
		return ans;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
