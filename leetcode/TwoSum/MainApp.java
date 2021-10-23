// Copyright (C) 2021 by iamslash

import java.util.*;

//           i
//   nums: 2 7 11 15
//      b: 7 2
// target: 9
// numMap: 2
//         0
// 

// 4ms 58.62% 42.8MB 16.40%
// hash map
// O(N) O(N)
class Solution {
    public int[] twoSum(int[] nums, int target) {
			// {num : idx}
			Map<Integer, Integer> numMap = new HashMap<>();
			for (int i = 0; i < nums.length; ++i) {
				int a = nums[i], b = target - a;
				if (numMap.containsKey(b)) {
					return new int[]{i, numMap.get(b)};					
				} else {
					numMap.put(a, i);
				}
			}
			return new int[0];
    }
}

//             i
//   nums: 3 2 7
//             j
// target: 6

// 0ms 100.00% 38.9MB 95.05%
// brute force
// O(N^2) O(1)
class Solution {
	public int[] twoSum(int[] nums, int target) {
		int n = nums.length;
		int[] pair = new int[2];
		for (int i = 1; i < n; ++i) {
			for (int j = i; j < n; ++j) {
				if (nums[j-i] + nums[j] == target) {
					pair[0] = j - i;
					pair[1] = j;
					return pair;
				}
			}
		}
		return pair;
	}
}

// 76ms 18.18% 41.3MB 45.00%
// brute force
// O(N^2) O(1)
class Solution {
	public int[] twoSum(int[] nums, int target) {
		int n = nums.length;
		int[] pair = new int[2];
		for (int i = 0; i < n; ++i) {
			for (int j = i+1; j < n; ++j) {
				if (nums[i] + nums[j] == target) {
					pair[0] = i;
					pair[1] = j;
					return pair;
				}
			}
		}
		return pair;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
