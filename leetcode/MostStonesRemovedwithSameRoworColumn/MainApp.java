// Copyright (C) 2021 by iamslash

import java.util.*;

// x 
//   x
// 4 - 2 - 0 = 2

// x 
// x
// 4 - 2 - 1 = 1

// x 
// x x
// 6 - 3 - 2 = 1

//    x
// x 
// x x
// 8 - 4 - 2 = 2

// 7ms 92.84% 39.3MB 38.79%
// disjoint set
// O(NlgN) O(N)
class Solution {
	private Map<Integer, Integer> parentMap = new HashMap<>();
	private int cntNotMerged = 0;
	private int find(int u) {
		if (parentMap.putIfAbsent(u, u) == null) {
			cntNotMerged++;
		}
		if (u != parentMap.get(u)) {
			parentMap.put(u, find(parentMap.get(u)));
		}
		return parentMap.get(u);
	}
	private void merge(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) {
			return;
		}
		parentMap.put(x, y);
		--cntNotMerged;
	}
	public int removeStones(int[][] stones) {
		for (int i = 0; i < stones.length; ++i) {
			merge(stones[i][0], stones[i][1] + 10000);
		}
		return stones.length - cntNotMerged;
	}	
}

public class MainApp {
  public static void main(String[] args) {
  }
}
