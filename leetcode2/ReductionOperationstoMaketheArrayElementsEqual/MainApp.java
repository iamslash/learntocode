// Copyright (C) 2021 by iamslash

import java.util.*;

//       i
// nums: 1 3 5
//  cnt: 1

// 52ms 62.26% 109.8MB 64.62%
// sort
// O(NlgN) O(1)
class Solution {
	public int reductionOperations(int[] nums) {
		Arrays.sort(nums);
		int n = nums.length, cnt = 0;
		for (int i = n-1; i >= 0; --i) {
			if (i < n-1 && nums[i] < nums[i+1]) {
				cnt += n-1-i;
			}
			if (nums[i] == nums[0]) {
				break;
			}
		}
		return cnt;
	}
}

// 8ms 99.53% 48.5MB 93.92%
// hash map
// O(N) O(N)
class Solution {
	public int reductionOperations(int[] nums) {
		int[] freq = new int[50001];
		for (int num : nums) {
			freq[num]++;
		}
		int cnt = 0, prv = 0, n = freq.length;
		for (int i = n-1; i >= 0; --i) {
			if (freq[i] == 0) {
				continue;
			}
			cnt += (freq[i] + prv);
			prv += freq[i];
		}
		return cnt - prv;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
