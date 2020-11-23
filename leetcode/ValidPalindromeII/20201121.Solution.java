// Copyright (C) 2020 by iamslash

// brute force
// O(N) O(1)
class Solution {
	private boolean palindrome(String s, int i, int j) {
		while (i < j) {
			if (s.charAt(i) != s.charAt(j))
				return false;
			i++;
			j--;
		}
		return true;
	}
	public boolean validPalindrome(String s) {
		for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
			if (s.charAt(i) != s.charAt(j)) {
				return palindrome(s, i, j-1) ||
						palindrome(s, i+1, j);
			}
		}
		return true;
	}
}
