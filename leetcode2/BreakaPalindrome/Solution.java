// Copyright (C) 2020 by iamslash

//  i 
// aacaa
//
// a

// // 3ms 21.20% 37.6MB 100.00%
// // linear traversal
// // O(N) O(1)
// class Solution {
// 	public String breakPalindrome(String s) {
// 		int n = s.length();
// 		if (n == 1)
// 			return "";
// 		// traverse 0 to n/2
// 		for (int i = 0; i < n/2; ++i) {
// 			if (s.charAt(i) != 'a') {
// 				return s.substring(0,i) + 'a' + s.substring(i+1);
// 			}
// 		}
// 		return s.substring(0,n-1) + 'b';
// 	}
// }

// 0ms 100.00% 37.1MB 100.00%
// linear traversal
// O(N) O(1)
class Solution {
	public String breakPalindrome(String s) {
		int n = s.length();
		if (n == 1)
			return "";
		// traverse 0 to n/2
		StringBuffer sb = new StringBuffer();
		for (int i = 0; i < n/2; ++i) {
			if (s.charAt(i) != 'a') {
				sb.append(s.substring(0,i));
				sb.append('a');
				sb.append(s.substring(i+1));
				return sb.toString();
			}
		}
		sb.append(s.substring(0, n-1));
		sb.append('b');
		return sb.toString();
	}
}
