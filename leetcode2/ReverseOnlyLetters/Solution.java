// Copyright (C) 2020 by iamslash

// 0ms 100.00% 38MB 8.70%
// two pointers
// O(N) O(1)
class Solution {
	public String reverseOnlyLetters(String s) {
		int i = 0, j = s.length() - 1;
		char[] arr = s.toCharArray();
		while (i < j) {
			while (i < j && !Character.isLetter(arr[i]))
				i++;
			while (i < j && !Character.isLetter(arr[j]))
				j--;
			if (i < j) {
				char c = arr[i];
				arr[i] = arr[j];
				arr[j] = c;
			}
      i++;
      j--;
		}
		return String.valueOf(arr);
	}
}
