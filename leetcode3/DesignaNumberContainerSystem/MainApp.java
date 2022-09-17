// Copyright (C) 2022 by iamslash

import java.util.*;

// 139ms 87.55% 107.1MB 90.34%
// bidirectional index, hash map, hash set
// change: O(NlgN) O(N)
//   find: O(1) O(N)
class NumberContainers {
    private Map<Integer, Integer> idx2numMap = new HashMap<>();
    private Map<Integer, SortedSet<Integer>> num2idxMap = new HashMap<>();
    
    public void change(int idx, int num) {
        if (idx2numMap.containsKey(idx)) {
            int org = idx2numMap.get(idx);
            num2idxMap.get(org).remove(idx);           
        }
        idx2numMap.put(idx, num);
        num2idxMap.putIfAbsent(num, new TreeSet<Integer>());
        num2idxMap.get(num).add(idx);
    }
    
    public int find(int num) {
        if (!num2idxMap.containsKey(num) ||
            num2idxMap.get(num).isEmpty()) {
            return -1;
        }
        return num2idxMap.get(num).first();
    }
}
