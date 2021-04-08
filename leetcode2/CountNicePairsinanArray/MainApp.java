// Copyright (C) 2021 by iamslash

import java.util.*;

//        i
// nums: 42 11 1 97
//           j

class Solution {
	private int reverseInteger(int n) {
		String s = String.format("%d", n);
		StringBuilder sb = new StringBuilder(s);
		sb.reverse();
		return sb.toString();
	}
	public int countNicePairs(int[] nums) {
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
