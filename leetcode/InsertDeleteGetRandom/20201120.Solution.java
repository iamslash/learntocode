// Copyright (C) 2020 by iamslash

import java.util.*;

// 20ms 27.47% 53.7MB 5.09%
// hash map
//    insert: O(1)
//    remove: O(1)
// getRandom: O(1)
class RandomizedSet {
	private List<Integer> nums = new ArrayList<Integer>();
	private Map<Integer, Integer> locs = new HashMap<>();
	private Random rand = new Random();
	public boolean insert(int val) {
		if (locs.containsKey(val))
			return false;
		locs.put(val, nums.size());
		nums.add(val);
		return true;
	}
    
	public boolean remove(int val) {
		if (!locs.containsKey(val))
			return false;
		int pos = locs.get(val);
		// swap position
		if (pos < nums.size() - 1) {
			int last = nums.get(nums.size() - 1);
			nums.set(pos, last);
			locs.put(last, pos);
		}
		locs.remove(val);
		nums.remove(nums.size() - 1);
		return true;
	}
    
	public int getRandom() {
		return nums.get(rand.nextInt(nums.size()));
	}
}
