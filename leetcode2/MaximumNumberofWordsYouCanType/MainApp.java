// Copyright (C) 2021 by iamslash

import java.util.*;

// 1ms 100.00% 39.3MB 80.00%
// hash map
// O(N) O(1)
class Solution {
	private boolean broken(String word, int[] brokenIdxs) {
		for (char c : word.toCharArray()) {
			if (brokenIdxs[c-'a'] > 0) {
				return true;
			}
		}
		return false;
	}
	public int canBeTypedWords(String text, String brokenLetters) {
		int[] brokenIdxs = new int[26];
		for (char c : brokenLetters.toCharArray()) {
			brokenIdxs[c-'a'] = 1;
		}
		String[] textArr = text.split(" ");
		int cnt = 0;
		for (String word : textArr) {
			if (broken(word, brokenIdxs) == false) {
				cnt++;
			}
		}
		return cnt;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
