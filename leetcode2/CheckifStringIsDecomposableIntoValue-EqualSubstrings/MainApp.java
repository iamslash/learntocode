// Copyright (C) 2021 by iamslash

import java.util.*;

//          i
//      1 1 
// cnt: 2

// 0ms 100.00% 37.3MB 100.00%
// linear traversal
// O(N) O(1)
class Solution {
	public boolean isDecomposable(String s) {
		int n = s.length(), cnt = 1;
		boolean found2 = false;
		if (n < 2) {
			return false;
		}
		for (int i = 1; i <= n; ++i) {
			if (i < n && s.charAt(i-1) == s.charAt(i)) {
				cnt++;
			} else {
				if (cnt % 3 == 1) {
					return false;
				} else if (cnt % 3 == 2) {
					if (found2) {
						return false;
					}
					found2 = true;
				} 
				cnt = 1;
			}
		}
		return found2;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
