// Copyright (C) 2020 by iamslash

import java.util.*;

// 1421ms 9.75% 65.2MB 23.08%
// bit manipulation
// O(N) O(N)
class Solution {
	private int encode(String a) {
		int bm = 0;
		for (char c : a.toCharArray()) {
			bm = bm | (1 << c - 'a');
		}
		return bm;
	}
	public List<Integer> findNumOfValidWords(String[] W, String[] P) {
		Map<Integer, List<Integer>> C = new HashMap<>();
		for (int i = 0; i < 26; i++) {
			C.put(i, new ArrayList<>());
		}
		for (String word : W) {
			int bm = encode(word);
			for (int i = 0; i < 26; ++i) {
				if ((bm & (1 << i)) > 0) {
					C.get(i).add(bm);
				}
			}																		 
		}
		List<Integer> ans = new ArrayList<>();
		for (String puzzle : P) {
			int bm = encode(puzzle);			
			int first = puzzle.charAt(0) - 'a';
			int cnt = 0;
			for (int key : C.get(first)) {
				if ((key & bm) == key) {
					cnt++;
				}
			}
			ans.add(cnt);
		}
		return ans;
	}
}
