// Copyright (C) 2021 by iamslash

// mruQueue: 1 4 5 7 8 3 6 2 

import java.util.*;

// 38ms 100.00% 40MB 100.00%
class MRUQueue {

	private List<Integer> mruQueue = new LinkedList<>();

	public MRUQueue(int n) {
		for (int i = 1; i <= n; ++i) {
			mruQueue.add(i);
		}
	}
    
	public int fetch(int k) {
		Integer num = mruQueue.remove(k-1);
		mruQueue.add(num);
		return num;
	}
}
