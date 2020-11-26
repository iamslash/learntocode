// Copyright (C) 2020 by iamslash

// 6ms 74.72% 39.5MB 59.01%
// brute force
// O(N) O(1)
class Solution {
	private boolean palindrome(String s, int l, int r) {
		while (l < r) {
			if (s.charAt(l) != s.charAt(r))
				return false;
			l++;
			r--;
		}
		return true;
	}
	public boolean validPalindrome(String s) {
		int i = 0, j = s.length()-1;
		while (i < j) {
			if (s.charAt(i) != s.charAt(j))
				return palindrome(s, i+1, j) ||
						palindrome(s, i, j-1);
			i++;
			j--;
		}
		return true;
	}
}
