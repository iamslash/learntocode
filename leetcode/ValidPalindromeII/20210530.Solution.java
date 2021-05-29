// Copyright (C) 2020 by iamslash

// 6,s 74.54% 39.8MB 31.70%
// brute force
// O(N) O(1)
class Solution {
	private boolean palindrome(String s, int l, int r) {
		while (l < r) {
			if (s.charAt(l) != s.charAt(r)) {
				return false;
			}
			l++;
			r--;
		}
		return true;
	}
	public boolean validPalindrome(String s) {
		int l = 0, r = s.length() - 1;
		while (l < r) {
			if (s.charAt(l) != s.charAt(r)) {
				return palindrome(s, l+1, r) ||
						palindrome(s, l, r-1);
			}
			l++;
			r--;
		}
		return true;
	}
}
