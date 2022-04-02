// Copyright (C) 2020 by iamslash

import java.util.*;

// 2ms 39.81% 38.9MB 18.63%
// deque
//     hit: O(1) O(N)
// getHits: O(1) O(N)
class HitCounter {
	private Deque<Integer> data = new ArrayDeque<>();
	private void clean(int ts) {
		int i = ts - 300;
		while (data.size() > 0 && data.peekFirst() <= i) {
			data.removeFirst();
		}
	}
	public void hit(int ts) {
		data.addLast(ts);
		clean(ts);
	}
	public int getHits(int ts) {
		clean(ts);
		return data.size();
	}
}
