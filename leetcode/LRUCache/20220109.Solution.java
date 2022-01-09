// Copyright (C) 2020 by iamslash

import java.util.*;

// 32ms 19.51% 58.2MB 7.05%
// hash map, doubly linked list
class ListNode {
	int key;
	int val;
	ListNode prev;
	ListNode next;
	public ListNode(int k, int v) {
		key = k;
		val = v;
	}
}
class DoublyLinkedList {
	private ListNode head = null;
	private ListNode tail = null;
	public void addFirst(ListNode node) {
		if (head == null) {
			head = node;
			tail = node;
			return;
		}
		head.prev = node;
		node.next = head;
		node.prev = null;
		head = node;
	}
	public ListNode removeLast() {
		ListNode node = tail;
		if (tail.prev != null) {
			tail.prev.next = null;
			tail = tail.prev;
		} else {
			head = null;
			tail = null;
		}
		return node;
	}
	public void promote(ListNode node) {
		if (node.prev == null)
			return;
		node.prev.next = node.next;
		if (node.next == null) {
			tail = node.prev;
		} else {
			node.next.prev = node.prev;
		}
		head.prev = node;
		node.next = head;
		node.prev = null;
		head = node;
	}
}
class LRUCache {
	private final Map<Integer, ListNode> cacheMap = new HashMap<>();
	private final DoublyLinkedList history = new DoublyLinkedList();
	private final int capacity;
	
	public LRUCache(int capacity) {
		this.capacity = capacity;
	}
    
	public int get(int key) {
		if (!cacheMap.containsKey(key))
			return -1;
		ListNode u = cacheMap.get(key);
		history.promote(u);
		return u.val;
	}
    
	public void put(int key, int val) {
		ListNode u;
		if (cacheMap.containsKey(key)) {
			u = cacheMap.get(key);
			u.val = val;
			history.promote(u);
			return;
		}
		if (cacheMap.size() == capacity) {
			ListNode v = history.removeLast();
			cacheMap.remove(v.key);
		}
		u = new ListNode(key, val);
		history.addFirst(u);
		cacheMap.put(u.key, u);
	}
}
