// Copyright (C) 2021 by iamslash

import java.util.*;

// (x-a)^2 + (y-b)^2 <= r^2

// 28ms 64.90% 39.2MB 97.98%
// math
// O(PQ) O(Q)
class Solution {
	private boolean isIn(int[] pt, int[] qr) {
		int x = pt[0], y = pt[1];
		int a = qr[0], b = qr[1], r = qr[2];
		return (x-a)*(x-a) + (y-b)*(y-b) <= r*r;
	}
	public int[] countPoints(int[][] points, int[][] queries) {
		int[] ans = new int[queries.length];
		for (int[] pt : points) {
			for (int i = 0; i < queries.length; ++i) {
				int[] qr = queries[i];
				if (isIn(pt, qr)) {
					ans[i]++;
				}
			}
		}						 
		return ans;		
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
