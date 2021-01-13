// Copyright (C) 2021 by iamslash

import java.util.*;

class ListNode {
	int val;
	ListNode next;
	ListNode() {}
	ListNode(int val) { this.val = val; }
	ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

// 3ms 87.23% 64.8MB 89.51%
class Solution {
	public ListNode swapNodes(ListNode h, int k) {
		ListNode p = h, src = null, dst = null;
		int i = k, n = 1;
		while (--i > 0) {
			p = p.next;
			n++;
		}
		src = p;
		while (p != null) {
			p = p.next;
			n++;
		}
		int j = n - k;
		p = h;
		while (--j > 0) {
			p = p.next;
		}
		dst = p;
		int t = src.val;
		src.val = dst.val;
		dst.val = t;
		return h;
	}
}
