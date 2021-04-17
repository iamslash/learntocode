// Copyright (C) 2021 by iamslash

import java.util.*;

// 6ms 16.10% 39.1MB 79.55%
// binary search
// O(KlgN) O(1)
class Solution {
  private int split(int[] S, int minSum) {
		int cnt = 0;
		int unitSum = 0;
		for (int sweet : S) {
			unitSum += sweet;
			if (unitSum >= minSum) {
				cnt++;
				unitSum = 0;
			}
		}
		return cnt;
	}
	public int maximizeSweetness(int[] sweetness, int K) {
		K = K + 1;
		int l = Arrays.stream(sweetness).min().getAsInt();
		int r = Arrays.stream(sweetness).sum();
		while (l < r) {
			int m = l + (r - l + 1) / 2;
			if (split(sweetness, m) >= K) {
				l = m;
			} else {
				r = m-1;
			}
		}
		return l;
	}
}

// 4ms 91.10% 39.1MB 79.55%
// binary search
// O(KlgN) O(1)
class Solution {
  private int split(int[] S, int minSum) {
		int cnt = 0;
		int unitSum = 0;
		for (int sweet : S) {
			unitSum += sweet;
			if (unitSum >= minSum) {
				cnt++;
				unitSum = 0;
			}
		}
		return cnt;
	}
	public int maximizeSweetness(int[] sweetness, int K) {
		K = K + 1;
		int l = Integer.MAX_VALUE, r = 0;
		for (int sweet : sweetness) {
			if (l > sweet) {
				l = sweet;
			}
			r += sweet;
		}
		while (l < r) {
			int m = l + (r - l + 1) / 2;
			if (split(sweetness, m) >= K) {
				l = m;
			} else {
				r = m-1;
			}
		}
		return l;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
