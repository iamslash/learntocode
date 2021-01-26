// Copyright (C) 2021 by iamslash

import java.util.*;

// 0ms 100.00% 37.5MB 69.25%
// brute force
// O(1) O(1)
class Solution {
	public String maximumTime(String time) {
		char[] timeArr = time.toCharArray();
		if (timeArr[0] == '?' && timeArr[1] == '?') {
			timeArr[0] = '2';
			timeArr[1] = '3';
		} else {
			if (timeArr[0] == '?') {
				if (timeArr[1] < '4') {
					timeArr[0] = '2';
				} else {
					timeArr[0] = '1';
				}
			}
			if (timeArr[1] == '?') {
				if (timeArr[0] == '2') {
					timeArr[1] = '3';
				} else {
					timeArr[1] = '9';
				}
			}
		}
		if (timeArr[3] == '?') {
			timeArr[3] = '5';
		}
		if (timeArr[4] == '?') {
			timeArr[4] = '9';
		}
		return new String(timeArr);
	}
}

// 1ms 62.63% 38.7MB 51.24%
// brute force
// O(1) O(1)
class Solution {
	public String maximumTime(String time) {
		char[] timeArr = time.toCharArray();
		if (timeArr[0] == '?') {
			if (timeArr[1] == '?' || timeArr[1] < '4') {
				timeArr[0] = '2';
			} else {
				timeArr[0] = '1';
			}
		}
		if (timeArr[1] == '?') {
			if (timeArr[0] == '2') {
				timeArr[1] = '3';
			} else {
				timeArr[1] = '9';
			}
		}

		if (timeArr[3] == '?') {
			timeArr[3] = '5';
		}
		if (timeArr[4] == '?') {
			timeArr[4] = '9';
		}
		return new String(timeArr);
	}
}
