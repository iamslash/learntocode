// Copyright (C) 2021 by iamslash

import java.util.*;

//                  i    
//   nums: 42 11 1 97
//         24 11 1 79
//         18  0 0 18
// cntMap: 18  0
//          2  2
//    ans:  2
//
// A[i] + rev(A[j]) = A[j] + rev(A[i])
// A[i] - rev(A[i]) = A[j] - rev(A[j])
// B[i] = A[i] - rev(A[i])

// 37ms 73.71% 53.4MB 57.93%
// hash map
// O(N) O(N)
class Solution {
	private final int MOD = 1_000_000_007;
	private int reverseInteger(int num) {
		int rev = 0;
		while (num > 0) {
			rev = rev * 10 + (num % 10);
			num /= 10;
		}
		return rev;
	}
	public int countNicePairs(int[] nums) {
		int ans = 0;
		Map<Integer, Integer> cntMap = new HashMap<>();
		for (int num : nums) {
			int rev = reverseInteger(num);
			int cnt = cntMap.getOrDefault(num - rev, 0);
			ans = (ans + cnt) % MOD;
      cntMap.put(num - rev, cnt + 1);
		}
		return ans;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
