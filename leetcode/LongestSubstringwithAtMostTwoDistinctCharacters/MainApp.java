// Copyright (C) 2021 by iamslash

import java.util.*;

//        i
//     s: e c e b a
//              j
// chSet: e c b
//        2 1 1
//   ans: 3

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
				cntMap.put(c, cntMap.get(c) - 1);
				if (cntMap.get(c) <= 0) {
					cntMap.remove(c);
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
