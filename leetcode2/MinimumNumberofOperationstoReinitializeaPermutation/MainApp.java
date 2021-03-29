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
		int[] arr = new int[n];
		for (int i = 0; i < n; ++i) {
			if (i % 2 == 0) {
				arr[i] = i / 2;
			} else {
				arr[i] = n / 2 + (i - 1) / 2;
			}
		}
		int ans = 1, i = arr[1];
		while (i != 1) {
			i = arr[i];
			ans++;
		}
		return ans;
	}
}

public class MainApp {
  public static void main(String[] args) {
		Solution sln = new Solution();
		// 2
		System.out.println(sln.reinitializePermutation(4));
		// 4
		System.out.println(sln.reinitializePermutation(6));
  }
}
