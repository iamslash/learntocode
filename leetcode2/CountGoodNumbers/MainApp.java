// Copyright (C) 2021 by iamslash

import java.util.*;

// even: 0 2 4 6 8
//  odd: 2 3 5 7
//
//    n: 4
//       5 4 5 4
//

// Time Limit Exceed
class Solution {
	public int countGoodNumbers(long n) {
		long MOD = 1000000007L;
		long cnt = 1;
		while (n-- > 0) {
			if (n % 2 > 0) {
				cnt = (cnt * 5) % MOD;
			} else {
				cnt = (cnt * 4) % MOD;
			}
		}
		return (int)cnt;
	}
}

// 0ms 100.00% 35.4MB 96.79%
// divide and conquor
// O(lg_len(N)) O(lg_len(N))
class Solution {
	private final int MOD = 1000000007;
	private long modPow(long x, long y) {
		// base
		if (y == 0) {
			return 1;
		}
		// recursion
		long p = modPow(x, y / 2);
		long additional = x;
		if (y % 2 == 0) {
			additional = 1;
		}
		return p * p * additional % MOD;
	}
	public int countGoodNumbers(long n) {
		return (int)(modPow(5, (n+1)/2) * modPow(4, n/2) % MOD);
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
