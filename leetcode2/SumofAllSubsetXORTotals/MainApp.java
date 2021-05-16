// Copyright (C) 2019 by iamslash

import java.util.*;

//    nums: 1 3
// subsets: 00     00
//          01     01
//          11     11
//          01 11  10
//    sums:         6
//
//    nums: a b c d e
//          0
//          a b c d e
//          ab ac ad ae bc bd be cd ce de
//          
//            

// bit manipulation
// O(2^N) O(1)
class Solution {
	public int subsetXORSum(int[] nums) {
		int ans = 0, n = nums.length, subsetCnt = 1 << nums.length;
		for (int bm = 1; bm < subsetCnt; ++bm) {
			int xorTotal = 0;
			for (int j = 0; j < n; ++j) {
				if ((bm & (1 << j)) > 0) {
					xorTotal ^= nums[j];
				}
			}
			ans += xorTotal;
		}
		return ans;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
