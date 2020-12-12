// Copyright (C) 2020 by iamslash

import java.util.*;
import java.util.stream.*;

// 34ms 13.51% 40.9MB 16.17%
// sort, hash map
// O(NlgN) O(1)
class Solution {
	public String frequencySort(String s) {
		int[] freqs = new int[256];
		for (int i = 0; i < s.length(); ++i) {
			freqs[s.charAt(i)]++;
		}
		List<Character> charList = s
				.chars()
				.mapToObj(e->(char)e)
				.collect(Collectors.toList());
		Collections.sort(charList,
										 (a, b) -> {
											 if (freqs[a] == freqs[b]) {
												 return -Integer.compare(a, b);
											 }
											 return -Integer.compare(freqs[a], freqs[b]);
										 });
		return charList
				.stream()
				.map(e->e.toString())
				.collect(Collectors.joining());						
	}
}
