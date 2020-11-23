// Copyright (C) 2020 by iamslash

//      i
// aleex
//        j
// aleeeex

// 0ms 100.00% 37.3MB 8.33%
// two pointers
// O(N) O(1)
class Solution {
	public boolean isLongPressedName(String name, String typed) {
		int i = 0, j = 0;
		while (j < typed.length()) {
			if (i < name.length() &&
					name.charAt(i) == typed.charAt(j)) {
				i++;
				j++;
			} else if (i > 0 && name.charAt(i-1) == typed.charAt(j)) {
				j++;
			} else {
				return false;
			}				
		}
		return i == name.length();
	}
}
