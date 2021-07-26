// Copyright (C) 2021 by iamslash

// 1ms 100.00% 37.3MB 96.60%
// hash map
// O(N) O(1)
class Solution {
	public boolean areOccurrencesEqual(String s) {
		int[] freqs = new int[26];
		for (char c : s.toCharArray()) {
			freqs[c-'a']++;
		}
		int bnd = freqs[s.charAt(0)-'a'];
		for (int i = 0; i < freqs.length; ++i) {
			if (freqs[i] > 0 && freqs[i] != bnd) {
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
