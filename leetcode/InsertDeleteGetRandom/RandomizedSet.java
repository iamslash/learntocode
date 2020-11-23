// Copyright (C) 2020 by iamslash

import java.util.*;

// 8ms 79.89% 44.2MB 33.56%
// Hash Map
// O(1) O(N)
class RandomizedSet {
	private List<Integer> values = new ArrayList<>();
	private Map<Integer, Integer> idxMap = new HashMap<>();
	private Random rnd = new Random();
	public boolean insert(int val) {
		if (idxMap.containsKey(val)) {
			return false;
		}
		idxMap.put(val, values.size());
		values.add(val);
		return true;
	}
	public boolean remove(int val) {
		if (!idxMap.containsKey(val)) {
			return false;
		}
		int pos = idxMap.get(val);
		values.set(pos, values.get(values.size()-1));
		idxMap.put(values.get(values.size()-1), pos);
		values.remove(values.size()-1);
		idxMap.remove(val);
		return true;
	}
	public int getRandom() {
		return values.get(rnd.nextInt(values.size()));
	}
}
