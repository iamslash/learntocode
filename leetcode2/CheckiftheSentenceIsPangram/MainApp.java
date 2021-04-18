// Copyright (C) 2021 by iamslash

import java.util.*;

// 2ms 25.00% 38.4MB 25.00%
// hash table
// O(N) O(1)
class Solution {
	public boolean checkIfPangram(String sentence) {
		int[] freq = new int[26];
		for (char c : sentence.toCharArray()) {
			freq[c-'a']++;
		}
		for (int cnt : freq) {
			if (cnt == 0) {
				return false;
			}
		}
		return true;
	}
}

// 0ms 100.00% 36.9MB 25.00%
// bitmask
// O(N) O(1)
class Solution {
	public boolean checkIfPangram(String sentence) {
		int bm = 0;
		for (char c : sentence.toCharArray()) {
			bm |= 1 << (c-'a');
		}
		return (bm + 1) == (1 << 26);
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
