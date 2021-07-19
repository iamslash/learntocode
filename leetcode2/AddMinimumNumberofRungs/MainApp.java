// Copyright (C) 2021 by iamslash

import java.util.*;

//  dist: 2
//          i
// rungs: 1 3 5 10
//  prev: 1
//   ans: 0

// 2ms 78.00% 51.9MB 91.54%
// linear traversal
// O(N) O(1)
class Solution {
	public int addRungs(int[] rungs, int dist) {
		int ans = 0;
		for (int i = 0; i < rungs.length; ++i) {
			if (i == 0) {
				ans += (rungs[i] - 1) / dist;
			} else {
				ans += (rungs[i] - rungs[i-1] - 1) / dist;
			}
		}
		return ans;
	}
}

// 2ms 78.00% 51.9MB 91.54%
// linear traversal
// O(N) O(1)
class Solution {
	public int addRungs(int[] rungs, int dist) {
		int prev = 0, ans = 0;
		for (int rung : rungs) {
			ans += (rung - prev - 1) / dist;
			prev = rung;
		}
		return ans;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
