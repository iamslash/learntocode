// Copyright (C) 2021 by iamslash

import java.util.*;

// 113ms 15.84% 166.4MB 17.87%
// doubly linked list, hash map
// get: O(1) O(N)
// put: O(1) O(N)
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
    public void addLast(ListNode u) {
        if (head == null) {
            head = u;
            tail = u;
            return;
        }
        // h ---- t u
        //          t
        tail.next = u;
        u.prev = tail;
        u.next = null;
        tail = u;
    }
    public ListNode removeFirst() {
        // h ---- t
        // u
        ListNode u = head;
        if (head.next != null) {
            head.next.prev = null;
            head = head.next;
        } else {
            head = null;
            tail = null;
        }
        return u;
    }
    public void touch(ListNode u) {
        // Return early when latest one
        if (u.next == null) {
            return;
        }
        // Remove node
        u.next.prev = u.prev;
        if (u.prev == null) {
            head = u.next;
        } else {
            u.prev.next = u.next;
        }
        addLast(u);
    }   
}
class LRUCache {

    private Map<Integer, ListNode> dataMap = new HashMap<>(); 
    private DoublyLinkedList history = new DoublyLinkedList();
    private int cap = 0;

    public LRUCache(int capacity) {
        cap = capacity;
    }
    
    public int get(int key) {
        if (!dataMap.containsKey(key)) {
            return -1;
        }
        ListNode u = dataMap.get(key);
        history.touch(u);
        return u.val;
    }
    
    public void put(int key, int value) {
        ListNode u;
        if (dataMap.containsKey(key)) {
            u = dataMap.get(key);
            u.val = value;
            history.touch(u);
            return;
        }
        if (dataMap.size() == cap) {
            ListNode v = history.removeFirst();
            dataMap.remove(v.key);
        }
        u = new ListNode(key, value);
        history.addLast(u);
        dataMap.put(u.key, u);
    }
}
