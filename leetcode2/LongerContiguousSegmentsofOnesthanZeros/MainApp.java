// Copyright (C) 2021 by iamslash

import java.util.*;

// 1 ms 66.67% 37.2MB 33.33%
// linear traversal
// O(N) O(1)
class Solution {
	public boolean checkZeroOnes(String s) {
		int[] cnts = new int[2];
		int[] maxCnts = new int[2];
		for (int i = 0; i < s.length(); ++i) {
			int pos = s.charAt(i)-'0';
			if (i == 0 || s.charAt(i-1) != s.charAt(i)) {
				cnts[pos] = 0;
			}
			cnts[pos]++;
			maxCnts[pos] = Math.max(maxCnts[pos], cnts[pos]);
		}
		return maxCnts[1] > maxCnts[0];
	}
}

// 0ms 100.00% 37MB 66.67%
// linear traversal
// O(N) O(1)
class Solution {
	public boolean checkZeroOnes(String s) {
		int maxZeroCnt = 0, maxOneCnt = 0, conZeroCnt = 0, conOneCnt = 0;
		for (char c : s.toCharArray()) {
			if (c == '0') {
				conZeroCnt++;
				conOneCnt = 0;
			} else {
				conOneCnt++;
				conZeroCnt = 0;
			}
			maxZeroCnt = Math.max(maxZeroCnt, conZeroCnt);
			maxOneCnt = Math.max(maxOneCnt, conOneCnt);
		}
		return maxOneCnt > maxZeroCnt;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}

