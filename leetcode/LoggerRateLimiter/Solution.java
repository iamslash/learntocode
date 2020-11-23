// Copyright (C) 2020 by iamslash

import java.util.*;

// 36ms 40.99% 47.5MB 64.09%
// hash table
// O(N) O(N)
class Logger {
	private Map<String, Integer> history = new HashMap<>();

	public Logger() {
        
	}
    
	public boolean shouldPrintMessage(int ts, String s) {
		if (history.containsKey(s) && ts - history.get(s) < 10)
			return false;
		history.put(s, ts);
		return true;
	}
}
