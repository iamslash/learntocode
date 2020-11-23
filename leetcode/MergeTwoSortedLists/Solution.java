// Copyright (C) 2020 by iamslash

// 1ms 30.42% 40.5MB 5.94%
// linked list
// O(N) O(N)
class Solution {
	public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
		// base
		if (l1 == null)
			return l2;
		if (l2 == null)
			return l1;
		// recursion
		if (l1.val < l2.val) {
			l1.next = mergeTwoLists(l1.next, l2);
			return l1;
		}
		l2.next = mergeTwoLists(l1, l2.next);
		return l2;
	}
}
