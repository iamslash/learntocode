// Copyright (C) 2021 by iamslash

import java.util.*;

// 0ms 100.00% 36.4MB 95.00%
// Sprague-Grundy throrem
// O(N) O(1)
class Solution {
	public boolean nimGame(int[] piles) {
		int ans = 0;
		for (int num : piles) {
			ans ^= num;
		}
		return ans > 0;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
