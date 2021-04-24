// Copyright (C) 2021 by iamslash

import java.util.*;

//        i
//     s: e c e b a
//              j
// chSet: e c b
//        2 1 1
//   ans: 3
// 
//        i
//     s: c c a a b b b
//                j
// chSet: c a b
//        2 2 1
//   ans: 4

// 4ms 85.55% 38.8MB 66.12%
// two pointers
// O(N) O(N)
class Solution {
	public int lengthOfLongestSubstringTwoDistinct(String s) {
		int i = 0, j = 0, n = s.length(), maxCnt = 0;
		if (n <= 1) {
			return n;
		}
		Map<Character, Integer> cntMap = new HashMap<>();
		while (j < n) {
			Character c = s.charAt(j);
			cntMap.put(c, cntMap.getOrDefault(c, 0) + 1);
			while (cntMap.size() > 2) {
				Character d = s.charAt(i);
				cntMap.put(d, cntMap.get(d) - 1);
				if (cntMap.get(d) <= 0) {
					cntMap.remove(d);
				}
				++i;
			}
			maxCnt = Math.max(maxCnt, j - i + 1);
			++j;
		}
		return maxCnt;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
