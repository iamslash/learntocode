// Copyright (C) 2021 by iamslash

import java.util.*;

// 2ms 41.16% 38.4MB 6.45%
// binary search
// O(NlgN) O(1)
class Solution {
	private boolean validGroup(int[] A, int maxGrp, long bndSum) {
		long sum = 0;
		int grpCnt = 1;
		for (int num : A) {
			sum += num;
			if (sum > bndSum) {
				sum = num;
				grpCnt++;
				if (grpCnt > maxGrp) {
					return false;
				}
			}
		}
		return true;
	}
	public int splitArray(int[] A, int grpCnt) {
		long lo = 0, hi = 0;
		for (int a : A) {
			hi += a;
			lo = Math.max(lo, a);
		}
		if (grpCnt == 1) {
			return (int)hi;
		}
		while (lo < hi) {
			long mi = (lo + hi) / 2;
			if (validGroup(A, grpCnt, mi) == false) {
				lo = mi + 1;
			} else {
				hi = mi;
			}
		}
		return (int)lo;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
