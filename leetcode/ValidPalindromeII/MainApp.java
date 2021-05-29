// Copyright (C) 2021 by iamslash

import java.util.*;
//      i
// s: a b c a
//        j

// 6ms 73.02% 39.6MB 45.42%
// brute force
// O(N) O(1)
class Solution {
	private boolean palindrome(String s, int i, int j) {
		while (i < j) {
			if (s.charAt(i++) != s.charAt(j--)) {
				return false;
			}
		}
		return true;
	}
	public boolean validPalindrome(String s) {
		int i = 0, j = s.length()-1;
		while (i < j) {
			if (s.charAt(i) != s.charAt(j)) {
				return palindrome(s, i+1, j) ||
						palindrome(s, i, j-1);
			}
			i++;
			j--;
		}
		return true;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
