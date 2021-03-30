// Copyright (C) 2021 by iamslash

import java.util.*;

//      n: 6
//  index: 1
// maxSum: 15
//
//    1
// 1  1  1
// 1  1  1  1
// 1  1  1  1  1  1
// l           r
// sum = 14, l = 0, r = 4		

// 5ms 17.80% 35.7MB 88.08%
// pyramid
// O(N) O(1)
class Solution {
	public int maxValue(int n, int index, int maxSum) {
		int sum = n;
		int l = index, r = index;
		int ans = 1;
		while (sum + (r-l+1) <= maxSum) {
			sum += r-l+1;
			l = l == 0 ? 0: l-1;
			r = r == n-1 ? r : r+1;
			ans++;
			if (l == 0 && r == n-1) {
				int step = (maxSum - sum) / n;
				sum += (step * n);
				ans += step;
			}
		}
		return ans;
	}
}

//      n: 4
//  index: 2
// maxSum: 6
//
// 
// 1 2 2 1

// 1ms 99.75% 35.6MB 97.19%
// binary search right most equal
// O(lgN) O(1)
class Solution {
	private long test(int n, int idx, int idxVal) {
		// Gauss summation of left side
		int bndVal = Math.max(idxVal - idx, 0);
		long ans = (long)(idxVal + bndVal) *
				(idxVal - bndVal + 1) / 2;
		// Gauss summation of right side
		bndVal = Math.max(idxVal - ((n-1) - idx), 0);
		ans += (long)(idxVal + bndVal) *
				(idxVal - bndVal + 1) / 2;
		return ans - idxVal;
	}
	public int maxValue(int n, int index, int maxSum) {
		maxSum -= n;
		int l = 0, r = maxSum;
		while (l < r) {
			int m = (l+r+1)/2;
			if (test(n, index, m) <= maxSum) {
				l = m;
			} else {			
				r = m - 1;
			}
		}
		return l+1;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
