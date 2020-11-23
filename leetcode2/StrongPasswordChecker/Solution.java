// Copyright (C) 2020 by iamslash

class Solution {
	public int strongPasswordChecker(String s) {
		int ans = 0, needSmallA = 1, needBigA = 1, needDigit = 1;
		char[] chars = s.toCharArray();
		int[] repeats = new int[chars.length];

		for (int i = 0; i < repeats.length; ) {
			if (Character.isLowerCase(chars[i]))
					needSmallA = 0;
			if (Character.isUpperCase(chars[i]))
				needBigA = 0;
			if (Character.isDigit(chars[i]))
				needDigit = 0;
			int j = i;
			while (i < chars.length && chars[i] == chars[j])
				++i;
			repeats[j] = i - j;
		}

		int totalMissing = needSmallA + needBigA + needDigit;
		if (chars < 6) {
			return totalMissing + Math.max(0, 6 - (chars.length + totalMissing));
		}
		int overLen = Math.max(chars.length - 20, 0);
		int leftOver = 0;
		ans += overLen;
		for (int k = 1; k < 3; ++k) {
			for (int i = 0; i < chars.length && overLen > 0; ++i) {
				if (repeats[i] < 3 || repeats[i] % 3 != (k - 1))
					continue;
				repeats[i] -= Math.min(overLen, k);
				overLen -= k;
			}
		}
		for (int i = 0; i < chars.length; ++i) {
			if (repeats[i] >= 3 && overLen > 0) {
				int need = repeats[i] - 2;
				repeats[i] -= overLen;
				overLen -= need;
			}
			if (repeats[i] >= 3)
				leftOver += repeats[i] / 3;
		}
		ans += Math.max(totalMissing, leftOver);
		return ans;
	}
}
