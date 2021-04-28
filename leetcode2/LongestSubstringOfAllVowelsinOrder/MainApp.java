// Copyright (C) 2021 by iamslash

import java.util.*;
//      aeiou
//  bm: 20020
// ans: 13

//                        i
// s: aeiaaioaaaaeiiiiouuuooaauuaeiu
//                          j

// two pointers
class Solution {
	Map<Character, Integer> idxMap = new HashMap<>();
	private boolean valid(int[] cnts, char c) {
		if (c == 'a') {
			return (cnts[1]+cnts[2]+cnts[3]+cnts[4]) == 0;
		} else if (c == 'e') {
			return (cnts[2]+cnts[3]+cnts[4]) == 0;
		} else if (c == 'i') {
			return (cnts[3]+cnts[4]) == 0;
		} else if (c == 'o') {
			return cnts[4] == 0;
		}
		return true;
	}
	private void addChar(int[] cnts, char c) {
		int i = idxMap.get(c);
		cnts[i]++;		
	}
	public int longestBeautifulSubstring(String s) {
		int i = 0, j = 0, n = s.length(), ans = 0;
		idxMap.put('a', 0);
		idxMap.put('e', 0);
		idxMap.put('i', 0);
		idxMap.put('o', 0);
		idxMap.put('u', 0);
		int[] cnts = new int[5];
		for (j = 0; j < n; ++j) {
			addChar(s.charAt(j));
		}
		return ans;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
