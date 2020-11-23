// Copyright (C) 2020 by iamslash

import java.util.*;

// 3ms 92.89% 40.6MB 8.48%
// DFS
// O(N) O(N)
class Solution {
	private int i = 0;
	private long parseNum(String s) {
		long n = 0;
		while (i < s.length() && Character.isDigit(s.charAt(i)))
			n = 10 * n + s.charAt(i++) - '0';
		return n;
	}
	private long parseExpr(String s) {
		List<Long> nums = new ArrayList<>();
		char op = '+';
		for (; i < s.length() && op != ')'; ++i) {
			if (s.charAt(i) == ' ')
				continue;
			long num = 0;
			if (s.charAt(i) == '(') {
				++i;
				num = parseExpr(s);
			} else {
				num = parseNum(s);
			}
			switch (op) {
				case '+':
					nums.add(num);
					break;
				case '-':
					nums.add(-num);
					break;
				case '*':
					nums.set(nums.size()-1, nums.get(nums.size()-1) * num);
					break;
				case '/':
					nums.set(nums.size()-1, nums.get(nums.size()-1) / num);
					break;
			}
			if (i < s.length())
				op = s.charAt(i);
		}
    // System.out.println(nums);
		long ans = 0;
		for (long n : nums)
			ans += n;
		return ans;
	}
	public int calculate(String s) {
		i = 0;
		return (int)parseExpr(s);
	}
}

