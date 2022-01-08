// Copyright (C) 2021 by iamslash

import java.util.*;

// sort
// O(NlgN) O(1)
class Solution {
	public int[][] kClosest(int[][] points, int K) {
		Arrays.sort(points, (a, b) -> {
				Integer da = a[0]*a[0] + a[1]*a[1];
				Integer db = b[0]*b[0] + b[1]*b[1];
				return da.compareTo(db);
			});
		int[][] ans = new int[K][2];
		for (int i = 0; i < K; ++i) {
			ans[i][0] = points[i][0];
			ans[i][1] = points[i][1];
		}
		return ans;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
