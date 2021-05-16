// Copyright (C) 2021 by iamslash

import java.util.*;

// memory1: 10
// memory2: 10
//       1: 
//
// memory1: 1000
// memory2: 1011
//       1: 

// 4ms 100.00% 36.9MB 100.00%
// linear traversal
// O(N) O(1)
class Solution {
	public int[] memLeak(int memory1, int memory2) {
		int i = 1;
		while (memory1 >= i || memory2 >= i) {
			if (memory1 >= memory2) {
				memory1 -= i;
			} else {
				memory2 -= i;
			}
			++i;
		}
		return new int[]{i, memory1, memory2};
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
