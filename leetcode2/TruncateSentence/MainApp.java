// Copyright (C) 2021 by iamslash

import java.util.*;

// 1ms 100.00% 37.3MB 100.00%
// split
// O(N) O(N)
class Solution {
	public String truncateSentence(String s, int k) {
		String[] sArr = s.split(" ");
		int n = Math.min(sArr.length, k);
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; ++i) {
			sb.append(sArr[i]);
			if (i < n-1) {
				sb.append(" ");
			}
		}
		return sb.toString();
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
