// Copyright (C) 2021 by iamslash

import java.util.*;

// 1950 1960
// 1960 1970
// 1970 1980
//              i
// beg: 1950 1960 1970
// end: 1960 1970 1980
//              j

class Solution {
	public int maximumPopulation(int[][] logs) {
		int[] cnts = new int[2050];
		for (int[] log : logs) {
			++cnts[log[0]];
			--cnts[log[1]];
		}
		int maxCntYear = 1950, maxCnt = 0;
		for (int i = 1950; i < 2050; ++i) {
		}
		return maxCntYear;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
