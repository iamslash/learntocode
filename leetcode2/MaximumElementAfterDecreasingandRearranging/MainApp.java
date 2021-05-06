// Copyright (C) 2021 by iamslash

import java.util.*;

// arr: 1 1 2 2 2
//
// arr: 1 100 1000

// Wrong Answer???
// sort
// O(NlgN) O(1)
class Solution {
	public int maximumElementAfterDecrementingAndRearranging(int[] arr) {
		int n = arr.length;
		Arrays.sort(arr);
		if (arr[n-1] >= n) {
			return n;
		}
		return arr[n-1];
	}
}

// 3ms 99.92% 55.1MB 91.62%
// sort
// O(NlgN) O(1)
class Solution {
	public int maximumElementAfterDecrementingAndRearranging(int[] arr) {
		int n = arr.length;
		Arrays.sort(arr);
		int maxNum = 1;
		for (int i = 1; i < n; ++i) {
			maxNum = Math.min(maxNum+1, arr[i]);
		}
		return maxNum;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
