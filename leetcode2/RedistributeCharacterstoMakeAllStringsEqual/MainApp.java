// Copyright (C) 2021 by iamslash

import java.util.*;

// modulo
// O(N) O(1)
// 2ms 99.81% 38.3MB 98.46%
class Solution {
	public boolean makeEqual(String[] words) {
		char[] freqs = new char[26];
		int charCnt = 0, wordCnt = words.length;
		for (String word : words) {
			for (char c : word.toCharArray()) {
				charCnt++;
				freqs[c-'a']++;
			}
		}
		if (charCnt % wordCnt != 0) {
			return false;
		}
		for (int i = 0; i < 26; ++i) {
			if (freqs[i] % wordCnt != 0) {
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
