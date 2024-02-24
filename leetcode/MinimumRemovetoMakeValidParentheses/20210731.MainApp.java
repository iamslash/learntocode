// Copyright (C) 2021 by iamslash

import java.util.*;

//        i
//    s: a*b(c)d
// stck:
//
//                    i 
//    s: lee(t(c)o)de*
// stck:

// 17ms 61.91% 39.9MB 44.25%
// stack
// O(N) O(N)
class Solution {
	public String minRemoveToMakeValid(String s) {
		StringBuilder sb = new StringBuilder(s);
		Stack<Integer> stck = new Stack<>();
		int n = s.length();
		for (int i = 0; i < n; ++i) {
			char c = s.charAt(i);
			if (c == '(') {
				stck.push(i);
			} else if (c == ')') {
				if (stck.size() > 0) {
					stck.pop();
				} else {
					sb.setCharAt(i, '*');
				}
			}
		}
		while (!stck.isEmpty()) {
			sb.setCharAt(stck.pop(), '*');
		}
		return sb.toString().replaceAll("\\*", "");
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
