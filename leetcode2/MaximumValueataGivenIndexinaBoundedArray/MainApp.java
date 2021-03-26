// Copyright (C) 2021 by iamslash

import java.util.*;

//      n: 4
//  index: 2
// maxSum: 6
//
// 
// 1 2 2 1

//      n: 6
//  index: 1
// maxSum: 10
//
//    ans: 0
// 1 1 1 1 1 1

// binary search right most equal
// O(NlgN) O(1)
class Solution {
	private long valid(int n, int index, int a) {
	}
	public int maxValue(int n, int index, int maxSum) {
		maxSum -= n;
		int l = 0, r = maxSum, m;
		while (l < r) {
			m = (l+r+1)/2;
			if (valid(n, index, m) <= maxSum) {
				l = m;
			} else {
				r = m-1;
			}
		}
		return l + 1;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
