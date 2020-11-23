// Copyright (C) 2020 by iamslash

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;
import java.util.ArrayList;
import java.util.Collections;

// // 8ms 36.54% 48MB 100.00%
// // stream
// // O(NlgN) O(N)
// class Solution {
// 	public List<Integer> filterRestaurants(int[][] R, int VF, int MP, int MD) {
// 		return Arrays.stream(R)
// 				.filter(a -> a[2] >= VF && a[3] <= MP && a[4] <= MD)
// 				.sorted((a, b) -> {
// 						if (a[1] == b[1])
// 							return b[0] - a[0];
// 						return b[1] - a[1];
// 					})
// 				.map(a -> a[0])
// 				.collect(Collectors.toList());
// 	}
// }

// 5ms 75.64% 48.1MB 100.00%
// sort
// O(NlgN) O(N)
class Solution {
	public List<Integer> filterRestaurants(int[][] R, int VF, int MP, int MD) {
		List<int[]> RList = new ArrayList<>();
		for (int[] r : R) {
			if (r[2] >= VF && r[3] <= MP && r[4] <= MD)
				RList.add(r);
		}
		Collections.sort(RList, (a, b) -> {
				if (a[1] == b[1])
					return b[0] - a[0];
				return b[1] - a[1];
			});
		List<Integer> ans = new ArrayList<>();
		for (int[] r : RList)
			ans.add(r[0]);
		return ans;
	}
}
