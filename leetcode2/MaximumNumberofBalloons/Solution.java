// Copyright (C) 2020 by iamslash
// balloon

// 2ms 72.68% 37.9MB 100.00%
// linear traversal
// O(N) O(1)
class Solution {
	public int maxNumberOfBalloons(String txt) {
		int[] cnts = new int[26];
		for (int i = 0; i < txt.length(); ++i) {
			cnts[txt.charAt(i) - 'a']++;
		}
		int cnt1 = Math.min(Math.min(cnts['b'-'a'], cnts['a'-'a']), cnts['n'-'a']);
		int cnt2 = Math.min(cnts['l'-'a'], cnts['o'-'a']);
        // System.out.printf("%d %d\n", cnt1, cnt2);
		return Math.min(cnt1, cnt2/2);
	}
}
