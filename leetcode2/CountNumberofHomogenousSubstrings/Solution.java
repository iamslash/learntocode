// Copyright (C) 2021 by iamslash

//      i
// s: a b b c c c a a
//          j

// 11ms 75.00% 39.9MB 75.00%
// math
// O(N) O(1)
class Solution {
	public int countHomogenous(String s) {
    final int MOD = 1_000_000_007;
		int i = 0, j = 0, n = s.length(), ans = 0;		
		while (i < n) {
			while (j < n && s.charAt(i) == s.charAt(j)) {
        j++;
 				ans = (ans + (j-i)) % MOD;
			}
			i = j;
		}
		return ans;
	}
}
