// Copyright (C) 2021 by iamslash

import java.util.*;

// [[1,4,5],[1,4,7],[4,7,1],[4,7,11]]
// begMap:  1  4
//         12 12
// endMap:  4  7
//         12 12

// [[1,7,9],[6,8,15],[8,10,7]]
//                  i
// begMap: 1  6     8 
//         9 15     7
// endMap:       7  8 10
//               9 15  7
//    mix: 9 24 15  7  0
//    ans: 1,6,9 6,7,24 7,8,15 8,0,7  

// line sweep, hash map
// O(N) O(N)
class Solution {
    public List<List<Long>> splitPainting(int[][] segments) {
        // { event timestamp : delta of color }
        Map<Integer, Long> evtMap = new TreeMap<>();
        for (int seg[] : segments) {
            evtMap.put(seg[0], evtMap.getOrDefault(seg[0], 0L) + seg[2]);
            evtMap.put(seg[1], evtMap.getOrDefault(seg[1], 0L) - seg[2]);
        }
        List<List<Long>> ans = new ArrayList<>();
        long idx = 0, mix = 0;
        for (int evt : evtMap.keySet()) {
            if (mix > 0) {
                ans.add(Arrays.asList(idx, (long)evt, mix));
            }
            mix += evtMap.get(evt);
            idx = evt;
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
