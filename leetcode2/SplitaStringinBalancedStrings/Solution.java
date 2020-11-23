// Copyright (C) 2020 by iamslash

//                 i
//    s: RLRRRLLRLL
// cntL: 0
// cntR: 0
//  ans: 2

// 0ms 100.00% 38.7MB 100.00%
// linear traversal
// O(N) O(1)
class Solution {
	public int balancedStringSplit(String s) {
		int cnt = 0, ans = 0, n = s.length();
		for (char c : s.toCharArray()) {
            if (c == 'L') 
                cnt++;
            else
                cnt--;
            if (cnt == 0)
                ans++;
		}
		return ans;
	}
}
