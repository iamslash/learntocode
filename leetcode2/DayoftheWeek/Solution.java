// Copyright (C) 2020 by iamslash

// 1971-1-1 is Friday.

// 0ms 100.00% 36.9MB 100.00%
// linear traversal
// O(N) O(1)
class Solution {
	public String dayOfTheWeek(int day, int month, int year) {
		String[] week = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
		int[] daysOfMonth = {31,28,31,30,31,30,31,31,30,31,30,31};
		int daysOfYear = 0;
		for (int i = 1971; i < year; ++i) {
			if (i % 4 == 0)
				daysOfYear += 366;
			else
				daysOfYear += 365;
		}
		if (year % 4 == 0)
			daysOfMonth[1] = 29;
		for (int i = 0; i < month - 1; ++i)
			daysOfYear += daysOfMonth[i];
		daysOfYear += day - 1;
		return week[(daysOfYear + 5) % 7];
	}
}
