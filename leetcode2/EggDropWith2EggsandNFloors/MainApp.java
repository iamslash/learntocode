// Copyright (C) 2021 by iamslash

import java.util.*;

//           f
// floors: 0 1 2
//

//         
// floors: 0 1 2 ... 100
//

// 47ms 41.30% 36.4MB 78.26%
// dynamic programming
// O(N) O(N)
class Solution {
	int[] C = new int[1001];
	public int twoEggDrop(int n) {
		// base
		// memo
		if (C[n] > 0) {
			return C[n];
		}
		// recursion
		C[n] = n;
		for (int i = 1; i <= n; ++i) {
			C[n] = Math.min(C[n], 1 + Math.max(i - 1, twoEggDrop(n - i)));
		}
		return C[n];
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
