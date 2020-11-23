// Copyright (C) 2020 by iamslash

import java.util.Deque;
import java.util.ArrayDeque;

// 20ms 58.37% 48.8MB 100.00%
// deque
// O(1) O(N)
class RecentCounter {
	private Deque<Integer> data = new ArrayDeque<>();

	public RecentCounter() {
        
	}
    
	public int ping(int t) {
		while (data.size() > 0 && t > 3000 &&
					 data.getFirst() < t - 3000) {
			data.pollFirst();
		}
		data.addLast(t);
		return data.size();
	}
}

