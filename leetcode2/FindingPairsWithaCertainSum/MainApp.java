// Copyright (C) 2021 by iamslash

import java.util.*;

//    nums1: 1 1 2 2 2 3
//    nums2: 1 4 5 4 5 4
// nums1Map: 1 2 3
//           2 3 1
// nums2Map: 1 4 5
//           1 3 2
//  valMap: 

// 149ms 97.45% 75.6MB 58.75%
// hash map
//   add: O(N) O(N)
// count: O(N) O(N)
class FindSumPairs {
	private int[] nums2;
	private Map<Integer, Integer> nums1Map = new HashMap<>();
	private Map<Integer, Integer> nums2Map = new HashMap<>();

	public FindSumPairs(int[] nums1, int[] nums2) {
		for (int num : nums1) {
			nums1Map.put(num, nums1Map.getOrDefault(num, 0) + 1);
		}
		for (int num : nums2) {
			nums2Map.put(num, nums2Map.getOrDefault(num, 0) + 1);
		}
		this.nums2 = nums2;
	}
    
	public void add(int idx, int val) {
		int oldVal = nums2[idx];
		int newVal = oldVal + val;
		// Update nums2Map with oldVal
		if (nums2Map.containsKey(oldVal)) {
			nums2Map.put(oldVal, nums2Map.get(oldVal) - 1);
			if (nums2Map.get(oldVal) == 0) {
				nums2Map.remove(oldVal);
			}
		}
		// Update nums2Map with newVal
		nums2Map.put(newVal, nums2Map.getOrDefault(newVal, 0) + 1);
		// Update nums2
		nums2[idx] = newVal;
	}
    
	public int count(int tot) {
    int sum = 0;
		for (Integer a : nums1Map.keySet()) {
			int b = tot - a;
			if (b <= 0 || !nums2Map.containsKey(b)) {
				continue;
			}
			sum += nums1Map.get(a) * nums2Map.get(b);
		}
		return sum;
	}
}

// 75ms 100.00% 63.2MB 98.99%
// hash map
//   add: O(N) O(N)
// count: O(N) O(N)
class FindSumPairs {
	int[] nums1, nums2, freqs;
	private final int MAXVAL = 1000001;
	public FindSumPairs(int[] nums1, int[] nums2) {
		this.nums1 = nums1;
		this.freqs = new int[MAXVAL];
		this.nums2 = nums2;
		for (int val : nums2) {
			this.freqs[val]++;
		}
	}

	public void add(int idx, int val) {
		this.freqs[nums2[idx]]--;
		nums2[idx] += val;
		this.freqs[nums2[idx]]++;
	}

	public int count(int tot) {
		int cnt = 0;
		for (int i = 0; i < nums1.length; ++i) {
			int tgt = tot - nums1[i];
			if (tgt >= 0 && tgt < MAXVAL) {
				cnt += freqs[tgt];
			}
		}
		return cnt;
	}	
}

public class MainApp {
  public static void main(String[] args) {
  }
}
