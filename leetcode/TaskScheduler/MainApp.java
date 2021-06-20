// Copyright (C) 2021 by iamslash
import java.util.*;

// 3ms 60.55% 55.4MB 9.26%
// hash map
// O(1) O(1)
class Solution {
	public int leastInterval(char[] tasks, int n) {
		int[] freqs = new int[26];
		int maxFreq = 0;
		for (char t : tasks) {
			freqs[t-'A']++;
			maxFreq = Math.max(maxFreq, freqs[t-'A']);
		}
		int unitCnt = maxFreq - 1;
		int unitLen = n + 1;
		int slotCnt = unitCnt * unitLen;
		for (int f : freqs) {
			if (f == maxFreq) {
				slotCnt++;
			}
		}
		return Math.max(slotCnt, tasks.length);
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
