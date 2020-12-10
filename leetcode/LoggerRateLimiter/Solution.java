// Copyright (C) 2020 by iamslash

import java.util.*;

// 27ms 73.98% 46.9MB 70.38%
// hash map
// O(1) O(N)
class Logger {
	private Map<String, Integer> history = new HashMap<>();
	public Logger() {		
	}
	public boolean shouldPrintMessage(int ts, String msg) {
		if (history.containsKey(msg) && ts - history.get(msg) < 10) {
			return false;
		}
		history.put(msg, ts);
		return true;
	}
}

