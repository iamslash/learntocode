// Copyright (C) 2021 by iamslash

import java.util.*;

//   c: 10
//      i
//   a: 11
//   b:  1
//      j
// ans:  0

// convert
// O(N) O(1)
class Solution {
	private String reverse(String a) {
		StringBuffer sb = new StringBuffer(a);
		return sb.reverse().toString();
	}
	public String addBinary(String a, String b) {
		a = reverse(a);
		b = reverse(b);
		String r = "";
		int i = 0, c = 0;
		while (i < a.length() || i < b.length()) {
			int d1 = i < a.length() ? a.charAt(i)-'0' : 0;			
			int d2 = i < b.length() ? b.charAt(i)-'0' : 0;
			
		}
		return reverse(r);
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
