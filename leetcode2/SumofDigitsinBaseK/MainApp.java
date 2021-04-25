// Copyright (C) 2021 by iamslash

import java.util.*;

// n: 42
// k:  2
// q: 42 21 10 5 2 1 0
// r:     0  1 0 1 0 1
//
//

// n: 34
// k:  6
// q: 34 5 0
// r:    4 5

// 0ms 100.00% 35.8MB 66.67%
// math
// O(lgK) O(1)
class Solution {
	public int sumBase(int n, int k) {
		int ans = 0;
		for(;n > 0; n /= k) {
			ans += n % k;
		}
		return ans;
	}
}

// 0ms 100.00% 36MB 66.67%
// math
// O(lgK) O(1)
class Solution {
	public int sumBase(int n, int k) {
		int sum = 0;
		while (n > 0) {
			ans += n % k;
			n /= k;
		}
		return sum;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
