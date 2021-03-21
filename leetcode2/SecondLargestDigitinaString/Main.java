// Copyright (C) 2021 by iamslash

//         a
// s: dfa12321afd
//        b    
//           i

//       a
// s: abc1111
//   b    
//           i

// 1ms 100.00% 39MB 100.00%
// brute force
// O(N) O(1)
class Solution {
	public int secondHighest(String s) {
		int num1st = -1, num2nd = -1;
		for (char c : s.toCharArray()) {
			if (c >= '0' && c <= '9') {
				int num = c - '0';
				if (num >= num1st) {					
					if (num > num1st) {
						num2nd = num1st;
						num1st = num;
					}
				} else if (num > num2nd) {
					num2nd = num;
				}
			}
		}
		return num2nd;
	}
}

class Main {
	public static void main(String[] args) {
	}
}
