// Copyright (C) 2020 by iamslash

//             i
//  s: l e v e l
//       j
// pi: 0 0 0 0 1
//    

//      i
//   s: a b a b a b
//      j
// lps: 0 0 0 0 0 0

//                  i
//   s: a b a b c a b a b
//        j  
// lps: 0 0 1 2 0 1 0 3 4

// 11ms 60.19% 40.3MB 66.56%
// KMP
// O(N) O(N)
class Solution {
	public String longestPrefix(String s) {
		int n = s.length();
		int[] lps = new int[n];
		for (int i = 1, j = 0; i < n; ++i) {
			while (j > 0 && s.charAt(i) != s.charAt(j))
				j = lps[j-1];
			if (s.charAt(i) == s.charAt(j))
				lps[i] = ++j;
		}
		return s.substring(0, lps[n-1]);
	}
}
