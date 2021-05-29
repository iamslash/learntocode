// Copyright (C) 2021 by iamslash

import java.util.*;

//     i
// hello
// leetcode

// hash map
// O(N) O(1)
class Solution {
	private boolean sorted(Map<Character, Integer> charMap,
												 String a, String b) {
		int m = a.length(), n = b.length();
		for (int i = 0; i < m && i < n; ++i) {
			if (a.charAt(i) == b.charAt(i)) {
				continue;
			}
			return charMap.get(a.charAt(i)) <
					charMap.get(b.charAt(i));
		}
		return m <= n;
	}
	public boolean isAlienSorted(String[] words, String order) {
		Map<Character, Integer> charMap = new HashMap<>();
		for (int i = 0; i < order.length(); ++i) {
			charMap.put(order.charAt(i), i);
		}
		for (int i = 1; i < words.length; ++i) {
			if (!sorted(charMap, words[i-1], words[i])) {
				return false;
			}
		}
		return true;
	}
}

// 0ms 100.00% 39MB 12.87%
// hash map
// O(N) O(1)
class Solution {
	private boolean sorted(int[] orderArr,
												 String a, String b) {
		int m = a.length(), n = b.length();
		for (int i = 0; i < m && i < n; ++i) {
			if (a.charAt(i) == b.charAt(i)) {
				continue;
			}
			return orderArr[a.charAt(i)-'a'] <
					orderArr[b.charAt(i)-'a'];
		}
		return m <= n;
	}
	public boolean isAlienSorted(String[] words, String order) {
		int[] orderArr = new int[26];		
		for (int i = 0; i < order.length(); ++i) {
			orderArr[order.charAt(i)-'a'] = i;
		}
		for (int i = 1; i < words.length; ++i) {
			if (!sorted(orderArr, words[i-1], words[i])) {
				return false;
			}
		}
		return true;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
