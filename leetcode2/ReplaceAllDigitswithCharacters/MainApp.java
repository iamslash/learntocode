// Copyright (C) 2021 by iamslash

import java.util.*;

// 0ms 100.00% 36.8MB 100.00%
// linear traversal
// O(N) O(N)
class Solution {
	public String replaceDigits(String s) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < s.length(); i += 2) {
			char c = s.charAt(i);
			sb.append(c);
			if (i + 1 < s.length()) {
				int diff = s.charAt(i+1) - '0';
				sb.append((char)(c + diff));
			}
		}
		return sb.toString();
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
