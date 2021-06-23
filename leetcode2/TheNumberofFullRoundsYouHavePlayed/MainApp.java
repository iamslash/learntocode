// Copyright (C) 2021 by iamslash

import java.util.*;

// 0ms 100.00% 36.9MB 97.53%
// match
// O(1) O(1)
class Solution {
	private int toNextQuarterMin(int TimeMin) {
		return ((TimeMin + 14) / 15) * 15;
	}
	private int toPrevQuarterMin(int TimeMin) {
		return (TimeMin / 15) * 15;
	}
	private int toMinutes(String s) {
		return Integer.parseInt(s.substring(0, 2)) * 60 +
				Integer.parseInt(s.substring(3));
	}
	public int numberOfRounds(String startTime, String endTime) {
		int startMin = toMinutes(startTime);
		int endMin = toMinutes(endTime);
		int startQuarterMin = toNextQuarterMin(startMin);
		int endQuarterMin = toPrevQuarterMin(endMin);
		if (startMin < endMin) {
			return Math.max(0, (endQuarterMin - startQuarterMin) / 15);
		}
		return (24 * 60 - startQuarterMin + endQuarterMin) / 15;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
