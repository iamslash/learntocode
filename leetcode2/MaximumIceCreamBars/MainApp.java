// Copyright (C) 2021 by iamslash

import java.util.*;

// 29ms 84.19% 55.3% 97.76%
// sort
// O(NlgN) O(1)
class Solution {
	public int maxIceCream(int[] costs, int coins) {
		Arrays.sort(costs);
		int cnt = 0;
		for (int cost : costs) {
			if (coins - cost < 0) {
				break;
			}
			coins -= cost;
			cnt++;
		}
		return cnt;
	}
}

// 5ms 99.85% 54.8MB 98.69%
// hash map
// O(N) O(N)
class Solution {
	public int maxIceCream(int[] costs, int coins) {
		int maxCoin = 0;
		for (int cost : costs) {
			maxCoin = Math.max(maxCoin, cost);
		}
		int[] coinCnts = new int[maxCoin+1];
		for (int cost : costs) {
			coinCnts[cost]++;
		}
		int ans = 0;
		for (int i = 1; coins >= i && i <= maxCoin; ++i) {
			int qty = Math.min(coinCnts[i], coins/i);
			ans += qty;
			coins -= qty * i;
		}
		return ans;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
