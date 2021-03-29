// Copyright (C) 2021 by iamslash

// perm: 0 1 2 3 4 5
//       0 3 1 4 2 5
//       0 4 3 2 1 5
//       0 2 4 1 3 5
//       0 1 2 3 4 5

// perm: 0 1 2 3 4 5 6 7 8 9
//       0 5 1 6 2 7 3 8 4 9
//       0 7 5 3 1 8 6 4 2 9
//       0 8 7 6 5 4 3 2 1 9
//       0 4 8 3 7 2 6 1 5 9
//       0 2 4 6 8 1 3 5 7 9
//       0 1 2 3 4 5 6 7 8 9

// 0ms 100.00% 35.6MB 97.64%
// math
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

// 0ms 100.00% 35.6MB 97.64%
// math
// O(N) O(1)
class Solution {
	public int reinitializePermutation(int n) {
		int ans = 0, idx = 1;
		while (ans == 0 || idx > 1) {
			if (idx < n/2) {
				idx *= 2;
			} else {
				idx = (idx - n/2) * 2 + 1;
			}
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
