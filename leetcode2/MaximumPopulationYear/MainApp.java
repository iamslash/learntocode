// Copyright (C) 2021 by iamslash

import java.util.*;

// 1950 1961
// 1960 1971
// 1970 1980
// 
// cnts: 1950 1960 1961 1970 1970 1980
//          1    1   -1    1   -1   -1
//          1    2    1    2    1    0

// 0ms 100.00% 38.2MB 20.00%
// line sweep
// O(N) O(1)
class Solution {
	public int maximumPopulation(int[][] logs) {
		int[] cnts = new int[2051];
		for (int[] log : logs) {
			++cnts[log[0]];
			--cnts[log[1]];
		}
		int maxCntYear = 1950, maxCnt = 0;
		for (int y = 1950; y < 2050; ++y) {
			cnts[y] += cnts[y-1];
			if (cnts[y] > maxCnt) {
				maxCntYear = y;
				maxCnt = cnts[y];
			}
		}
		return maxCntYear;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
