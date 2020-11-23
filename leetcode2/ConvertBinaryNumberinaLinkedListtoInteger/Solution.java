// Copyright (C) 2020 by iamslash

// linked list
// O(N) O(1)
class Solution {
	public int getDecimalValue(ListNode u) {
		int sum = 0;
		while (u != null) {
			sum = (sum << 1) + u.val;
			u = u.next;
		}
		return sum;
	}
}
