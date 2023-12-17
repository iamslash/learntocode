// Copyright (C) 2023 by iamslash

import java.util.*;

// 48ms 76.49% 58.4MB 65.70%
// binary indexing, doubly linked list
// O(N) O(1)
class Bucket {
    int cnt;
    Set<String> keySet;
    Bucket next;
    Bucket prev;
    public Bucket(int cnt) {
        this.cnt = cnt;
        this.keySet = new HashSet<>();
    }
}

class AllOne {
    private Bucket head;
    private Bucket tail;
    private Map<Integer, Bucket> cntBucketMap;
    private Map<String, Integer> keyCntMap;

    private void updateKey(String key, int offset) {
        int cnt = keyCntMap.get(key);
        keyCntMap.put(key, cnt + offset);
        Bucket u = cntBucketMap.get(cnt);
        Bucket v;
        if (cntBucketMap.containsKey(cnt + offset)) {
            v = cntBucketMap.get(cnt + offset);
        } else {
            v = new Bucket(cnt + offset);
            cntBucketMap.put(cnt + offset, v);
            addBucketAfter(v, offset == 1 ? u: u.prev);
        }
        v.keySet.add(key);
        removeKeyFromBucket(u, key);
    }

    private void removeKeyFromBucket(Bucket bucket, String key) {
        bucket.keySet.remove(key);
        if (bucket.keySet.size() == 0) {
            removeBucketFromList(bucket);
            cntBucketMap.remove(bucket.cnt);
        }
    }

    private void removeBucketFromList(Bucket bucket) {
        bucket.prev.next = bucket.next;
        bucket.next.prev = bucket.prev;
        bucket.next = null;
        bucket.prev = null;
    }

    private void addBucketAfter(Bucket v, Bucket u) {
        v.prev = u;
        v.next = u.next;
        u.next.prev = v;
        u.next = v;
    }

    public AllOne() {
        head = new Bucket(Integer.MIN_VALUE);
        tail = new Bucket(Integer.MAX_VALUE);
        head.next = tail;
        tail.prev = head;
        cntBucketMap = new HashMap<>();
        keyCntMap = new HashMap<>();
    }
    
    public void inc(String key) {
        if (keyCntMap.containsKey(key)) {
            updateKey(key, 1);
        } else {
            keyCntMap.put(key, 1);
            if (head.next.cnt != 1) {
                addBucketAfter(new Bucket(1), head);
            }
            head.next.keySet.add(key);
            cntBucketMap.put(1, head.next);
        }        
    }
    
    public void dec(String key) {
        if (keyCntMap.containsKey(key)) {
            int cnt = keyCntMap.get(key);
            if (cnt == 1) {
                keyCntMap.remove(key);
                removeKeyFromBucket(cntBucketMap.get(cnt), key);
            } else {
                updateKey(key, -1);
            }
        }
    }
    
    public String getMaxKey() {
        if (tail.prev == head) {
            return "";
        }
        return (String)tail.prev.keySet.iterator().next();
    }
    
    public String getMinKey() {
        if (head.next == tail) {
            return "";
        }
        return (String)head.next.keySet.iterator().next();
    }
}
