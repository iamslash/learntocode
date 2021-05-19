
// Copyright (C) 2021 by iamslash

import java.util.*;

//        i
// s: 0 1 1 0 1 0
//          j
// 
//
// s: 1 1 0 0 1
// s: 1 0 1 0 1
//        

// 1ms 99.66% 37.3MB 72.96%
// linear traversal
// O(N) O(1)
class Solution {
	public int minSwaps(String s) {
		int cnt0 = 0, cnt1 = 0, miss0 = 0, miss1 = 0;
		for (char c : s.toCharArray()) {
			if (c == '0') {
				cnt0++;
			} else {
				cnt1++;
			}
		}
		if (Math.abs(cnt0 - cnt1) > 1) {
			return -1;
		}
		for (int i = 0; i < s.length(); i += 2) {
			if (s.charAt(i) != '0') {
				miss0++;
			}
			if (s.charAt(i) != '1') {
				miss1++;
			}
		}
		if (cnt0 == cnt1) {
			return Math.min(miss0, miss1);
		}
		if (cnt0 > cnt1) {
			return miss0;
		}
		return miss1;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
