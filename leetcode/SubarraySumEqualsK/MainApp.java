// Copyright (C) 2021 by iamslash

import java.util.*;

//       k: 2
//    nums: 1 1 1
//              i
//     sum: 3
//     cnt: 2
// freqMap: 0 1 2
//          1 1 1

// 46ms 28.12% 58.4MB 5.18%
// hash map
// O(N) O(N)
class Solution {
	public int subarraySum(int[] nums, int k) {
		Map<Integer, Integer> freqMap = new HashMap<>();
		freqMap.put(0, 1);
		int cnt = 0, sum = 0;
		for (int num : nums) {
			sum += num;
			if (freqMap.containsKey(sum-k)) {
				cnt += freqMap.get(sum-k);
			}
			freqMap.put(sum, freqMap.getOrDefault(sum, 0) + 1);
		}
		return cnt;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
