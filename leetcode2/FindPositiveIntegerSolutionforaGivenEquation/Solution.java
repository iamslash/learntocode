// Copyright (C) 2020 by iamslash

// 2ms 22.11% 39MB 100.00%
// linear traversal
// O(N) O(N)
class Solution {
	public List<List<Integer>> findSolution(CustomFunction cfun, int z) {
		List<List<Integer>> ans = new ArrayList<>();
		int x = 1, y = 1000;
		while (x <= 1000 && y > 0) {
			int r = cfun.f(x, y);
			if (r == z) {
				ans.add(Arrays.asList(x++, y--));				
			} else if (r < z) {
				x++;
			} else {
				y--;
			}
		}
		return ans;
	}
}
