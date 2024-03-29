// Copyright (C) 2022 by iamslash

import java.util.*;

// 282ms 5.08% 152.5MB 11.63%
// binary search
// O(NlgM) O(N)
class Solution {
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        int n = spells.length, m = potions.length;
        Arrays.sort(potions);
        TreeMap<Long, Integer> ptn2idxMap = new TreeMap<>();
        ptn2idxMap.put(Long.MAX_VALUE, m);
        for (int i = m-1; i >= 0; --i) {
            ptn2idxMap.put((long)potions[i], i);
        }
        // for (int i = 0; i < m; ++i) {
        //     ptn2idxMap.put((long)potions[i], i);
        // }        
        System.out.println(ptn2idxMap);
        for (int i = 0; i < n; ++i) {
            long need = (success + spells[i] - 1) / spells[i];
            spells[i] = m - ptn2idxMap.ceilingEntry(need).getValue();
            // System.out.printf("need: %d, ceilingKey: %d, celingVal: %d\n", need, ptn2idxMap.ceilingEntry(need).getKey(), ptn2idxMap.ceilingEntry(need).getValue());
        }
        return spells;
    }
}
