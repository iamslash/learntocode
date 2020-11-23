// Copyright (C) 2020 by iamslash

// 3ms 20.43% 45.8MB 6.82%
// greedy
// O(N) O(N)
class Solution {
	public int[] diStringMatch(String s) {
		int n = s.length(), i = 0, j = n;
		int[] ans = new int[s.length()+1];
		for (int k = 0; k < n; k++) {
			char c = s.charAt(k);
			if (c == 'I') {
				ans[k] = i++;
			} else {
				ans[k] = j--;
			}
		}
    if (s.charAt(n-1) == 'I')
      ans[n] = j;
    else
      ans[n] = i;
		return ans;
	}
}
