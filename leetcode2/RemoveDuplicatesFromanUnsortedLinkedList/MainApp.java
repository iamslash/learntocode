// Copyright (C) 2021 by iamslash

import java.util.*;

class ListNode {
	int val;
	ListNode next;
	ListNode() {}
	ListNode(int val) { this.val = val; }
	ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

//          b p
//    list: d 1 2 3 2
//            h
// 	cntMap:	1 2 3
//          1 2 1

// 81ms 100.00% 52.7MB 100.00%
// linked list, hash map
// O(N) O(N)
class Solution {
	public ListNode deleteDuplicatesUnsorted(ListNode head) {
		Map<Integer, Integer> cntMap = new HashMap<>();
		ListNode p = head;
		while (p != null) {
      cntMap.put(p.val, cntMap.getOrDefault(p.val, 0)+1);
      p = p.next;
		}
		ListNode dumb = new ListNode(0, head);
    dumb.next = head;
		ListNode b = dumb;    
		p = head;
		while (p != null) {
      if (cntMap.get(p.val) > 1) {
				b.next = p.next;
			} else {
				b = p;
			}
			p = p.next;
		}
		return dumb.next;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
