// Copyright (C) 2021 by iamslash

import java.util.*;

// 1068ms 20.00% 45.4MB 20.00%
// linear traversal
// O(N) O(N)
class Solution {
	public String largestOddNumber(String s) {
		String maxOddStr = "";
		StringBuilder sb = new StringBuilder();
		for (char c : s.toCharArray()) {
			sb.append(c);
			if (Integer.valueOf(c-'0') % 2 == 1) {
				maxOddStr = sb.toString();
			}
		}
		return maxOddStr;
	}
}

// 1ms 80.00% 39.8MB 40.00%
// backward
// O(N) O(1)
class Solution {
	public String largestOddNumber(String s) {
		int pos = s.length() - 1;
		while (pos >= 0 && (s.charAt(pos) - '0') % 2 == 0) {
			pos--;
		}
		return s.substring(0, pos+1);
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
