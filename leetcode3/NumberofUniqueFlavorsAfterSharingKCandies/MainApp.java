// Copyright (C) 2022 by iamslash

import java.util.*;

//       k: 1
//            i
// candies: 2 4 5
//

// 93ms 33.78% 98.4MB 31.98%
// slding window, hash map
// O(N) O(N)
class Solution {
    public int shareCandies(int[] candies, int k) {
        int n = candies.length, maxUniq = 0, allUniq = 0, i = 0;
        Map<Integer, Integer> freqMap = new HashMap<>();
        for (i = 0; i < n; ++i) {
            freqMap.put(candies[i], freqMap.getOrDefault(candies[i], 0) + 1);
        }
        allUniq = freqMap.size();
        if (k == 0) {
            return allUniq;
        }
        for (i = 0; i < k; ++i) {
            int candySub = candies[i];
            freqMap.put(candySub, freqMap.get(candySub) - 1);
            if (freqMap.get(candySub) == 0) {
                freqMap.remove(candySub);
            }
        }
        maxUniq = freqMap.size();
        while (i < n) {
            int candySub = candies[i], candyAdd = candies[i-k];
            freqMap.put(candySub, freqMap.get(candySub) - 1);
            freqMap.put(candyAdd, freqMap.getOrDefault(candyAdd, 0) + 1);
            if (freqMap.get(candySub) == 0) {
                freqMap.remove(candySub);
            }
            maxUniq = Math.max(maxUniq, freqMap.size());
            ++i;
        }
        return maxUniq;
    }
}
