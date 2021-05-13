// Copyright (C) 2021 by iamslash

import java.util.*;

//                 f
//      F: 1 2 3 1 2
// sumMap: 1 2 3
//         1 3 6 7 9
//    ans: 8

// 15ms 33.33% 56.2MB 27.27%
// partial sum, hash map
// O(N) O(N)
class Solution {
	public int maximumBeauty(int[] flowers) {
		Map<Integer, Integer> psMap = new HashMap<>();
		int sum = 0;
		int ans = Integer.MIN_VALUE;
		for (int f : flowers) {
			if (psMap.containsKey(f)) {
				int rangeSum = sum - psMap.get(f);
				ans = Math.max(ans, rangeSum + 2 * f);
			}
			if (f > 0) {
				sum += f;
			}
			psMap.putIfAbsent(f, sum);
		}
		return ans;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
