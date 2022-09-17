// Copyright (C) 2022 by iamslash

import java.util.*;

// 184ms 66.44% 173MB 25.82%
// hash map, hash set
// change: O(NlgN) O(N)
//   find: O(1) O(N)
class NumberContainers {
    Map<Integer, Integer> idx2numMap = new HashMap<>();
    Map<Integer, TreeSet<Integer>> num2idxsMap = new HashMap<>();
    
    public void change(int idx, int num) {
        if (idx2numMap.containsKey(idx)) {
            // Remove idx from num2idxMap
            int orgNum = idx2numMap.get(idx);
            num2idxsMap.get(orgNum).remove(idx);
        }
        idx2numMap.put(idx, num);
        num2idxsMap.putIfAbsent(num, new TreeSet<Integer>());
        num2idxsMap.get(num).add(idx);
    }
    
    public int find(int num) {
        if (!num2idxsMap.containsKey(num) ||
           num2idxsMap.get(num).isEmpty()) {
            return -1;
        }
        return num2idxsMap.get(num).first();
    }
}
// edge cases
//
// Runtime Error Message:
// java.util.NoSuchElementException
//   at line 1602, java.base/java.util.TreeMap.key
//   at line 291, java.base/java.util.TreeMap.firstKey
//   at line 391, java.base/java.util.TreeSet.first
//   at line 23, NumberContainers.find
//   at line 68, __Driver__.__helperSelectMethod__
//   at line 87, __Driver__.__helper__
//   at line 108, __Driver__.main
// Last executed input:
// ["NumberContainers","change","find","change","find","find","find"]
// [[],[1,10],[10],[1,20],[10],[20],[30]]

public class MainApp {
  public static void main(String[] args) {
  }
}
