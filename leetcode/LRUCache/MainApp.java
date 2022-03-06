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

// 118ms 25.64% 190.4MB 5.05%
// hash map, linked hash set
// get: O(1) O(N)
// put: O(1) O(N)
class LRUCache {
    private Map<Integer, Integer> valueMap = new HashMap<>(); 
    private Set<Integer> history = new LinkedHashSet<>();
    private int cap = 0;

    public LRUCache(int capacity) {
        cap = capacity;
    }

    private void touch(int val) {
        history.remove(val);
        history.add(val);
    }
   
    public int get(int key) {
        // miss
        if (!valueMap.containsKey(key)) {
            return -1;
        }
        // hit
        Integer val = valueMap.get(key);
        touch(key);
        return val;
    }
    
    public void put(int key, int val) {
        // hit
        if (valueMap.containsKey(key)) {
            touch(key);
            valueMap.put(key, val);
            return;
        }
        // evict
        if (valueMap.size() == cap) {
            Integer firstKey = history.iterator().next();
            valueMap.remove(firstKey);
            history.remove(firstKey);
        }
        // save
        history.add(key);
        valueMap.put(key, val);
    }
}

// 105ms 36.39% 124.7MB 67.11%
// hash map
class LRUCache extends LinkedHashMap<Integer, Integer> {
    private int cap;

    public LRUCache(int capacity) {
        super(capacity, 0.75f, true);
        this.cap = capacity;
    }

    public int get(int key) {
        Integer val = super.get(key);
        return val == null ? -1 : val;
    }

    @Override
    protected boolean removeEldestEntry(Map.Entry eldest) {
        return size() > cap;
    }
}
