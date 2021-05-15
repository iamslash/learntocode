// Copyright (C) 2021 by iamslash

import java.util.*;

//   c: 10
//      i
//   a: 11
//   b:  1
//      j
// ans:  0
// c a b  r c
// 0 0 0  0 0
// 0 0 1  1 0
// 0 1 0  1 0
// 0 1 1  0 1
// 1 0 0  1 0
// 1 0 1  0 1
// 1 1 0  0 1
// 1 1 1  1 1

// 2ms 71.57% 37.9MB 54.95%
// linear traversal
// O(N) O(1)
class Solution {
	public String addBinary(String a, String b) {
		int n = a.length(), m = b.length();
		StringBuffer sb = new StringBuffer();
		int i = 0, c = 0;
		while (i < n || i < m) {
			int d1 = i < n ? a.charAt(n-1-i)-'0' : 0;			
			int d2 = i < m ? b.charAt(m-1-i)-'0' : 0;
			int num = c + d1 + d2;
			sb.append(num%2);
			c = num > 1 ? 1 : 0;
			++i;
		}
		if (c > 0) {
			sb.append(c);
		}
		return sb.reverse().toString();
	}
}

// 1ms 100.00% 37.3MB 95.22%
// linear traversal
// O(N) O(1)
class Solution {
	public String addBinary(String a, String b) {
		int n = a.length(), m = b.length();
		StringBuilder sb = new StringBuilder();
		int i = 0, c = 0;
		while (i < n || i < m) {
			int d1 = i < n ? a.charAt(n-1-i)-'0' : 0;			
			int d2 = i < m ? b.charAt(m-1-i)-'0' : 0;
			int num = c + d1 + d2;
			sb.append(num%2);
			c = num > 1 ? 1 : 0;
			++i;
		}
		if (c > 0) {
			sb.append(c);
		}
		return sb.reverse().toString();
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
