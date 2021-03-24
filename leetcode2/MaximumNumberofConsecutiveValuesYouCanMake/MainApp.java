// Copyright (C) 2021 by iamslash

import java.util.*;

//          i
// coins: 1 3
//   ans: 2
//
//     
//              i
// coins: 1 1 1 4
//   ans: 8

// 15ms 98.82% 46.6MB 80.92%
// greedy, sort
// O(NlgN) O(1)
class Solution {
	public int getMaximumConsecutive(int[] coins) {
		Arrays.sort(coins);
		int ans = 1;
		for (int coin : coins) {
			if (coin > ans) {
				return ans;
			}
			ans += coin;
		}
		return ans;
	}
}

public class MainApp {
  public static void main(String[] args) {
		Solution sln = new Solution();
		// 2
		System.out.println(sln.getMaximumConsecutive(new int[]{1,3}));
		// 8
		System.out.println(sln.getMaximumConsecutive(new int[]{1,1,1,4}));
  }
}
