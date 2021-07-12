// Copyright (C) 2021 by iamslash

import java.util.*;

// hash map
// O(N) O(1)
class Solution {
	public int countPalindromicSubsequence(String s) {
		int n = s.length();
		int[] firstIdxs = new int[26];
		int[] lastIdxs = new int[26];
		Arrays.fill(firstIdxs, Integer.MAX_VALUE);
		for (int i = 0; i < n; ++i) {
			int charIdx = s.charAt(i) - 'a';
			firstIdxs[charIdx] = Math.min(firstIdxs[charIdx], i);
			lastIdxs[charIdx] = i;
		}
		int cnt = 0;
		for (int charIdx = 0; charIdx < 26; ++charIdx) {
			cnt += s.substring(firstIdxs[charIdx]+1, lastIdxs[charIdx])
					.chars()
					.distinct()
					.count();
		}
		return cnt;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
