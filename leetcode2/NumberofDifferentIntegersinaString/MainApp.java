// Copyright (C) 2021 by iamslash

import java.util.*;

// 14ms 100.00% 39.3MB 100.00%
// linear traversal
// O(N) O(N)
class Solution {
	public int numDifferentIntegers(String word) {
		Set<String> numSet = new HashSet<>();
		String[] numArr = word.split("\\D");
		for (String s : numArr) {
			s = s.trim();
			if (!s.isEmpty()) {
				s = s.replaceAll("^0*", "");
				numSet.add(s);
			}
		}
		return numSet.size();
	}
}


public class MainApp {
  public static void main(String[] args) {
		Solution sln = new Solution();
		// 3
		System.out.println(sln.numDifferentIntegers("a123bc34d8ef34"));
		// 2
		System.out.println(sln.numDifferentIntegers("leet1234code234"));
		// 1
		System.out.println(sln.numDifferentIntegers("a1b01c001"));
  }
}
