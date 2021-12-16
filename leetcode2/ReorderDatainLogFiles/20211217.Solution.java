// Copyright (C) 2020 by iamslash

import java.util.Arrays;
import java.util.Comparator;

// 5ms 67.37% 39.6MB 64.71%
// sort
// O(NlgN) O(1)
class Solution {
	public String[] reorderLogFiles(String[] L) {
		Comparator<String> cmp = new Comparator<>() {
  		@Override
			public int compare(String a, String b) {
				String[] aArr = a.split(" ", 2);
				String[] bArr = b.split(" ", 2);
				boolean aLetter = Character.isLetter(aArr[1].charAt(0));
				boolean bLetter = Character.isLetter(bArr[1].charAt(0));
				if (aLetter && bLetter) {
					int comp = aArr[1].compareTo(bArr[1]);
					return comp == 0 ? aArr[0].compareTo(bArr[0]) : comp;
				} else if (!aLetter && bLetter) {
					return 1;
				} else if (aLetter && !bLetter) {
					return -1;
				}
				return 0;
			}
		};
		Arrays.sort(L, cmp);
		return L;
	}
}
