// Copyright (C) 2021 by iamslash

import java.util.*;

// 6ms 23.04% 38.9MB 51.98%
// sliding window, hash map
// O(N) O(N)
class Solution {
	public int countGoodSubstrings(String s) {
		Map<Character, Integer> cntMap = new HashMap<>();
		int n = s.length(), ans = 0;
		for (int i = 0; i < n; ++i) {
			// Consume
			if (i > 2) {
				Character pc = s.charAt(i-3);
				cntMap.put(pc, cntMap.get(pc)-1);
				if (cntMap.get(pc) == 0) {
					cntMap.remove(pc);
				}
			}
			// Produce
			Character c = s.charAt(i);
			cntMap.put(c, cntMap.getOrDefault(c, 0) + 1);
			// Update
			if (cntMap.size() == 3) {
				ans++;
			}
		}
		return ans;
	}
}

// 0ms 100.00% 37MB 93.56%
// sliding window
// O(N) O(1)
class Solution {
	public int countGoodSubstrings(String s) {
		int n = s.length(), ans = 0;
		for (int i = 0; i < n; ++i) {
			if (i >= 2) {
				char a = s.charAt(i-2);
				char b = s.charAt(i-1);
				char c = s.charAt(i);
				if (a != b && b != c && c != a) {
					ans++;
				}
			}
		}
		return ans;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
