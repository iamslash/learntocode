// Copyright (C) 2021 by iamslash

import java.util.*;

// chalk: 5 1 5
//     k: 22
//        0

// 1ms 100.005 55.3MB 67.57%
// linear traversal
// O(N) O(1)
class Solution {
	public int chalkReplacer(int[] chalk, int k) {
		int n = chalk.length, sum = 0;
		for (int i = 0; i < n; ++i) {
			sum += chalk[i] ;
			k -= chalk[i];
			if (k < 0) {
				return i;
			}
		}
		k = k % sum;
		for (int i = 0; i < n; ++i) {
			k -= chalk[i];
			if (k < 0) {
				return i;
			}
		}
		return 0;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
