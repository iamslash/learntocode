// Copyright (C) 2021 by iamslash

import java.util.*;

// 123
// 456

// 5ms 67.61% 39.4MB 51.94%
// brute force
// O(MN) O(M+N)
class Solution {
	public String multiply(String num1, String num2) {
		char[] num1Arr = num1.toCharArray();
		char[] num2Arr = num2.toCharArray();
		if (num1Arr[0] == '0' || num2Arr[0] == '0') {
			return "0";
		}
		int m = num1Arr.length, n = num2Arr.length;
		char[] ansArr = new char[m + n];
		Arrays.fill(ansArr, '0');
		int o = ansArr.length - 1;
		for (int j = n-1; j >= 0; --j) {
			int c = num2Arr[j] - '0', k = o, carry = 0;
			for (int i = m-1; i >= 0; --i) {
				int tmp = c * (num1Arr[i]-'0') + carry + ansArr[k]-'0';
				ansArr[k--] = (char)((tmp % 10) + '0');
				carry = tmp / 10;
			}
			if (carry > 0) {
				ansArr[k] += carry;
			}
			o--;
		}
		if (ansArr[0] == '0') {
			return new String(ansArr, 1, ansArr.length-1);
		}
		return new String(ansArr);				
	}
}
