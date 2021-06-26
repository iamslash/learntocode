// Copyright (C) 2021 by iamslash

import java.util.*;


// 11ms 100.00% 39.3MB 100.00%
// O(N^2) O(N)
class Solution {
	public String removeOccurrences(String s, String part) {
		String prv = s;
		String cur = s;
		do {
			prv = cur;
			cur = cur.replaceFirst(part, "");
		} while (!cur.equals(prv));
		return cur;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
