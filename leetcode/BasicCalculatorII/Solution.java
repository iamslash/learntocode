// Copyright (C) 2019 by iamslash

//             i
// + 3 * 2 + 1
// rslt: 3
// last: 6
//  opr: +
//  opd: 1

import java.util.Stack;

// 14ms 42.45% 42.3MB 5.97%
// stack
// O(N) O(N)
public class Solution {
	public int calculate(String s) {
		if (s == null || s.length() == 0)
			return 0;
		Stack<Integer> stack = new Stack<>();
		s = "+" + s.replaceAll(" ", "");
		int i = 0;
		while (i < s.length()) {
			char opr = s.charAt(i++);
			int opd = 0;
			while (i < s.length() && Character.isDigit(s.charAt(i))) {
				opd = opd * 10 + s.charAt(i++) - '0';
			}
			if (opr == '+' || opr == '-') {
				stack.push(opr == '+' ? opd : -opd);
			} else if (opr == '*') {
				stack.push(stack.pop() * opd);
			} else if (opr == '/') {
				stack.push(stack.pop() / opd);
			}
		}
		int rslt = 0;
		for (int num : stack) {
			rslt += num;
		}
		return rslt;
	}
	
  public static void main(String[] args) {
		Solution sln = new Solution();
		System.out.println(sln.calculation("3+2*2"));
		System.out.println(sln.calculation(" 3/2 "));
		System.out.println(sln.calculation(" 3+5 / 2 "));
  }
}
