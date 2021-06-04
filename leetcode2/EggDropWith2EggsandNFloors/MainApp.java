// Copyright (C) 2021 by iamslash

import java.util.*;

//           f
// floors: 0 1 2
//

//         
// floors: 0 1 2 ... 100
//

// 47ms 41.30% 36.4MB 78.26%
// recursive dynamic programming
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

// 0ms 100.00% 37.3MB 78.26%
// math, linear search
// O(N) O(1)
class Solution {
	public int twoEggDrop(int n) {
    int ans = 1;
    while (ans * (ans + 1) / 2 < n) {
      ans++;
    }
    return ans;
	}
}

// 0ms 100.00% 35.5MB 100.00%
// math, binary search
// O(N) O(N)
class Solution {
	public int twoEggDrop(int n) {
    int l = 1, h = 1000, m = 0;
    while (l < h) {
      m = l + (h-l)/2;
      if (m*(m+1)/2 < n) {
        l = m + 1;
      } else {
        h = m;
      }
    }
    return l;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
