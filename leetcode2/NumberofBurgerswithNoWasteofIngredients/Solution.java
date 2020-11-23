// Copyright (C) 2020 by iamslash

import java.util.List;
import java.util.Collection;
import java.util.ArrayList;
import java.util.Arrays;

// T: 16, C: 7

// // 1ms 100.00% 39.4MB 100.00%
// // equations
// // O(1) O(1)
// class Solution {
// 	public List<Integer> numOfBurgers(int T, int C) {
// 		// System.out.printf("%b %b %b\n", T % 2 == 0, C * 2 <= T, T <= C * 4);
// 		if (T % 2 == 0 && C * 2 <= T && T <= C * 4) {
// 			int J = T / 2 - C;
// 			int S = C * 2 - T / 2;
// 			return Arrays.asList(J, S);
// 		}
// 		return new ArrayList<>();
// 	}
// 	public static void main(String[] args) {
// 		Solution sln = new Solution();
// 		int T = 16, C = 7;
// 		System.out.println(sln.numOfBurgers(T, C));
// 	}
// }

// 974ms 7.01% 39.5MB 100.00%
// brute force
// O(J) O(1)
class Solution {
	public List<Integer> numOfBurgers(int T, int C) {
		int cntBurger = C;
		for (int J = 0; J <= cntBurger; J++) {
			int S = cntBurger - J;
			if (T == 4 * J + 2 * S)
				return Arrays.asList(J, S);
		}
		return new ArrayList<>();
	}
}
