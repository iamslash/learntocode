// Copyright (C) 2021 by iamslash

import java.util.*;

// triplets: 3,4,5
//           4,5,6
//   target: 3,2,5

// triplets: 2 5 3
//           1 8 4
//           1 7 5
//   target: 2 7 5

// linear traversal
// O(N) O(1)
// 1ms 98.31% 108.9MB 50.62%
class Solution {
	public boolean mergeTriplets(int[][] triplets, int[] target) {
		boolean a = false, b = false, c = false;
		for (int[] triplet : triplets) {
			if (triplet[0] == target[0] && triplet[1] <= target[1] && triplet[2] <= target[2]) {
				a = true;
			}
			if (triplet[1] == target[1] && triplet[0] <= target[0] && triplet[2] <= target[2]) {
				b = true;
			}
			if (triplet[2] == target[2] && triplet[0] <= target[0] && triplet[1] <= target[1]) {
				c = true;
			}
			if (a && b && c) {
				return true;
			}
		}
		return false;
	}
}

// 7ms 45.25% 93.9MB 94.80%
// greedy
// O(N) O(1)
class Solution {
	public boolean mergeTriplets(int[][] triplets, int[] tgt) {
		int[] cand = new int[]{0, 0, 0};
		for (int[] tri : triplets) {
			if (tri[0] <= tgt[0] &&
					tri[1] <= tgt[1] &&
					tri[2] <= tgt[2]) {
				cand = new int[]{Math.max(cand[0], tri[0]),
												 Math.max(cand[1], tri[1]),
												 Math.max(cand[2], tri[2])};
			}
		}
		return Arrays.equals(tgt, cand);
	}
}


public class MainApp {
  public static void main(String[] args) {
  }
}
