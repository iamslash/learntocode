// Copyright (C) 2021 by iamslash

import java.util.*;

// a^2 + b^2 = c^2
// a <= b

// 5ms 100.00% 39.2MB 100.00%
// brute force
// O(N^2)
class Solution {
	public int countTriples(int n) {
		boolean[] squares = new boolean[n*n+1];
		for (int i = 1; i <= n; ++i) {
			squares[i*i] = true;
		}
		int cnt = 0;
		for (int a = 1; a <= n; ++a) {
			for (int b = a; a*a + b*b <= n*n; ++b) {
				if (squares[a*a + b*b]) {
					cnt += 2;
				}
			}
		}
		return cnt;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
