// Copyright (C) 2021 by iamslash

import java.util.*;

// 1ms 51.72% 37MB 90.76%
// brute force
// O(N) O(N)
class Solution {
	public String numString(String word) {
		StringBuilder sb = new StringBuilder();
		for (char c : word.toCharArray()) {
			sb.append(c - 'a');
		}
		return sb.toString();
	}
	public boolean isSumEqual(String firstWord, String secondWord, String targetWord) {
		Integer f = Integer.parseInt(numString(firstWord));
		Integer s = Integer.parseInt(numString(secondWord));
		Integer t = Integer.parseInt(numString(targetWord));
		return (f + s) == t;
	}
}

// 0ms 100.00% 38.3MB 71.47%
// brute force
// O(N) O(1)
class Solution {
	public int toNum(String word) {
		int sum = 0, n = word.length();
		for (int i = 0; i < n; ++i) {
			sum = sum * 10 + (word.charAt(i) - 'a');
		}
		return sum;
	}
	public boolean isSumEqual(String firstWord, String secondWord, String targetWord) {
		int f = toNum(firstWord);
		int s = toNum(secondWord);
		int t = toNum(targetWord);
		return (f + s) == t;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
