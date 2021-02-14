// Copyright (C) 2021 by iamslash

//      i
// s: a b b c c c a a
//          j

// math
// O(N) O(1)
class Solution {
	public int countHomogenous(String s) {
    final int MOD = 1_000_000_009;
		int i = 0, j = 0, n = s.length(), ans = 0;		
		while (i < n) {
			while (j < n && s.charAt(i) == s.charAt(j)) {
				j++;
			}
			ans = (ans + ((j-i)*(j-i+1)/2) % MOD) % MOD;
			i = j;
		}
		return ans;
	}
}
