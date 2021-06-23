// Copyright (C) 2021 by iamslash

import java.util.*;

//       k: 7
// ribbons: 9 7 5
// 

// 32ms 84.54% 52MB 42.53%
// binary search
// O(NlgN) O(1)
class Solution {
	public boolean cuttable(int[] ribbons, int k, int len) {
		int cnt = 0;
		for (int ribbon: ribbons) {
			cnt += (ribbon / len);
		}
		return cnt >= k;
	}
	public int maxLength(int[] ribbons, int k) {
		int lo = 1, hi = (int)1e5 + 1;
		while (lo < hi) {
			int mi = lo + (hi - lo) / 2;
			if (cuttable(ribbons, k, mi)) {
				lo = mi + 1;
			} else {
				hi = mi;
			}
		}
		return lo-1;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
