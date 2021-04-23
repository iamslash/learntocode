// Copyright (C) 2021 by iamslash

import java.util.*;

//   .   .
//     .
//   .   .
// ,

// 
//   .   . .
//   
//   .   . .
// 0     

// 363ms 34.59% 39.3MB 57.21%
// hash map
// O(N^2) O(N^2)
class Solution {
	public int minAreaRect(int[][] points) {
		Map<Integer, Set<Integer>> rectMap = new HashMap<>();
		for (int[] p : points) {
			rectMap.putIfAbsent(p[0], new HashSet<>());
			rectMap.get(p[0]).add(p[1]);
		}
		int ans = Integer.MAX_VALUE;
		for (int[] p1 : points) {
			for (int[] p2 : points) {
				// same x or same y
				if (p1[0] == p2[0] || p1[1] == p2[1]) {
					continue;
				}
				if (rectMap.get(p1[0]).contains(p2[1]) &&
						rectMap.get(p2[0]).contains(p1[1])) {
					ans = Math.min(ans, Math.abs(p1[0] - p2[0]) *
												 Math.abs(p1[1] - p2[1]));
				}
			}
		}
		return ans == Integer.MAX_VALUE ? 0 : ans;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
