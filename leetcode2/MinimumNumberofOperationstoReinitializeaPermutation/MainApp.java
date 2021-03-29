// Copyright (C) 2021 by iamslash

// perm: 0 1 2 3 4 5
//       0 3 1 4 2 5
//       0 4 3 2 1 5
//       0 2 4 1 3 5
//       0 1 2 3 4 5

// brute force
// O(N) O(1)
class Solution {
	public int reinitializePermutation(int n) {
		int ans = 0, idx = 1;
		do {
			if (idx < n/2) {
				idx *= 2;
			} else {
				idx = (idx - n/2) * 2 + 1;
			}
			ans++;
		} while (idx != 1);
		return cnt;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
