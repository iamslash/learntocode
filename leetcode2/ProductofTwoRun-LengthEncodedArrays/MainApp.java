// Copyright (C) 2021 by iamslash

import java.util.*;

//                 i
// encoded1: 1,3 2,3
// encoded2: 6,3 3,3
//                 j
//      ans: 6,6

//                     i
// encoded1: 1,3 2,1 3,2
// encoded2: 2,3 3,3
//                 j
//      ans: 2,3 6,1 9,2

// 33ms 32.08% 90.8MB 64.15%
// linear traversal
// O(N) O(N)
class Solution {
	public List<List<Integer>> findRLEArray(int[][] enc1, int[][] enc2) {
		List<List<Integer>> ans = new ArrayList<>();
		int i = 0, j = 0, n = enc1.length, m = enc2.length;
		while (i < n && j < m) {
			int prd = enc1[i][0] * enc2[j][0];
			int cnt = Math.min(enc1[i][1], enc2[j][1]);
			// Update ans
			if (ans.size() == 0 || ans.get(ans.size()-1).get(0) != prd) {
				ans.add(Arrays.asList(prd, 0));
			}
			List<Integer> item = ans.get(ans.size()-1);
			item.set(1, item.get(1) + cnt);
			// Update enc1, enc2 count
			enc1[i][1] -= cnt;
			enc2[j][1] -= cnt;
			// forward i, j
			if (enc1[i][1] == 0) {
				++i;
			}
			if (enc2[j][1] == 0) {
				++j;
			}
		}
		return ans;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
