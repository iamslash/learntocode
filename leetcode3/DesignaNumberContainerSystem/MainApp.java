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

public class MainApp {
  public static void main(String[] args) {
  }
}
