// Copyright (C) 2020 by iamslash

import java.util.Arrays;

// // 1ms 85.22% 37.5MB 100.00%
// // sort
// // O(NlgN) O(N)
// class Solution {
// 	public int heightChecker(int[] H) {
// 		int[] A = Arrays.copyOf(H, H.length);
// 		Arrays.sort(A);
// 		int ans = 0;
// 		for (int i = 0; i < H.length; ++i)
// 			if (A[i] != H[i])
// 				ans++;
// 		return ans;		
// 	}
// }

//                 i
//    H: 1 1 4 2 1 3
//             j
// freq: 1 2 3 4
//       0 0 0 0 
//  ans: 3

// 0ms 100.00% 37.1MB 100.00%
// two pointers
// O(N) O(1)
class Solution {
	public int heightChecker(int[] H) {
		int[] freq = new int[101];
		for (int h : H)
			freq[h]++;
		int ans = 0, j = 0;
		for (int i = 0; i < H.length; ++i) {
			while (freq[j] == 0)
				j++;
			if (j != H[i])
				ans++;
			freq[j]--;
		}
		return ans;		
	}
}
