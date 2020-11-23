// Copyright (C) 2020 by iamslash

//    i
// aaaba
//     j

// 0ms 100.00% 37.5MB 100.00MB
// two pointers
// O(N) O(1)
class Solution {
	public int countLetters(String S) {
		int n = S.length();
		int ans = 0;
		for (int i = 0, j = 0; i < n; i = j) {
			j = i;
			while (j < n && S.charAt(i) == S.charAt(j))
				++j;
			int d = j - i;
			ans += d * (d + 1) / 2;
		}
		return ans;
	}
}
