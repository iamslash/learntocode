// Copyright (C) 2021 by iamslash

import java.util.*;

// 19ms 66.67% 49.2MB 33.33%
// hash map, hash set
// O(N) O(N)
class Solution {
	public int[] findingUsersActiveMinutes(int[][] logs, int k) {
		Map<Integer, Set<Integer>> user2min = new HashMap<>();
		for (int[] log : logs) {
			user2min.putIfAbsent(log[0], new HashSet<>());
			user2min.get(log[0]).add(log[1]);
		}
		int ans[] = new int[k];
		user2min.forEach((key, val) -> {
				int cnt = val.size();
				if (cnt <= k) {
					ans[cnt-1]++;
				}
			});
		return ans;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
