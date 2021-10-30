// Copyright (C) 2021 by iamslash

import java.util.*;

// ____
//  ____
//
// ____
//      ____
//
// ____
//  __

// 6ms 29.53% 51.8MB 8.84%
// brute force
// O(N) O(N)
class Solution {
	public int[][] intervalIntersection(int[][] firstList, int[][] secondList) {
		List<int[]> ans = new ArrayList<>();
		int m = firstList.length, n = secondList.length, i = 0, j = 0;
		while (i < m && j < n) {
			int[] first = firstList[i];
			int[] second = secondList[j];
			int x = Math.max(first[0], second[0]);
			int y = Math.min(first[1], second[1]);
			if (x <= y) {
				ans.add(new int[]{x, y});
			}
			if (first[1] < second[1]) {
				++i;
			} else {
				++j;
			}		 
		}		
		return ans.toArray(new int[0][]);
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
