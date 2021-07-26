// Copyright (C) 2021 by iamslash

import java.util.*;

// 1ms 97.29% 38.7MB 81.89%
// linear traversal
// O(N) O(1)
class Solution {
	private int reduce(String digitStr) {
		int sum = 0;
		for (char c : digitStr.toCharArray()) {
			sum += c-'0';
            // System.out.println(sum);            
		}
		return sum;
	}
	public int getLucky(String s, int k) {
		StringBuilder sb = new StringBuilder();
		for (char c : s.toCharArray()) {
			sb.append(String.valueOf(c-'a'+1));
		}
		String digitStr = sb.toString();
		if (digitStr.length() == 1) {
			return Integer.parseInt(digitStr);
		}
		int sum = 0;
		while (k-- > 0 && digitStr.length() > 1) {
			sum = reduce(digitStr);
			digitStr = String.valueOf(sum);
		}
		return sum;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
