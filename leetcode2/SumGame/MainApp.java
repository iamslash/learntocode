// Copyright (C) 2021 by iamslash

import java.util.*;

// 8ms 83.23% 39.3MB 92.11%
// linear traversal
// O(N) O(1)
class Solution {
	public boolean sumGame(String num) {
		int n = num.length();
		double ans = 0;
		for (int i = 0; i < n; ++i) {
			double delta = 1;
			if (i < (n/2)) {
				delta = -1;
			}
			char c = num.charAt(i);
			if (c == '?') {
				delta *= 4.5;
			} else {
				delta *= (c - '0');
			}
			ans += delta;
		}
		return ans != 0.0;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
