// Copyright (C) 2020 by iamslash

// 18ms 64.71% 54.1MB 16.71%
// seperate chaning
class ListNode {
	int key, val;
	ListNode next;
	public ListNode(int key, int val) {
		this.key = key;
		this.val = val;
	}
}
class MyHashMap {
	private final ListNode[] data = new ListNode[10000];
	private int index(int key) {
		return Integer.hashCode(key) % data.length;
	}
	private ListNode find(ListNode u, int key) {
		ListNode cur = u;
		ListNode prv = null;
		while (cur != null && cur.key != key) {
			prv = cur;
			cur = cur.next;
		}
		return prv;
	}
 	public void put(int key, int val) {
		int i = index(key);
		if (data[i] == null)
			data[i] = new ListNode(-1, -1);
		ListNode prev = find(data[i], key);
		if (prev.next == null)
			prev.next = new ListNode(key, val);
		else
			prev.next.val = val;
	}
	public int get(int key) {
		int i = index(key);
		if (data[i] == null)
			return -1;
		ListNode u = find(data[i], key);
		if (u.next == null)
			return -1;
		return u.next.val;
	}
	public void remove(int key) {
		int i = index(key);
		if (data[i] == null)
			return;
		ListNode prev = find(data[i], key);
		if (prev.next == null)
			return;
		prev.next = prev.next.next;
	}
}
