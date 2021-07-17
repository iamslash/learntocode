// Copyright (C) 2021 by iamslash

import java.util.*;

// bit manipulation
// O(N) O(1)
class Solution {
	public long wonderfulSubstrings(String word) {
		// the count of state
		long cnt[] = new long[1024];
		cnt[0] = 1;
		long ans = 0;
		int bm = 0;
		for (char c : word.toCharArray()) {
			bm ^= 1 << (c-'a');
			ans += cnt[bm];
			for (int i = 0; i < 10; ++i) {
				ans += cnt[bm ^ (1 << i)];
			}
			++cnt[bm];
		}
		return ans;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
