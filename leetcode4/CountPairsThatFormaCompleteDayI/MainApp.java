// Copyright (C) 2024 by iamslash

import java.util.*;

// hours: 12 12 30 24 24

// 1ms 100.00% 42.1MB 100.00%
// brute force
// O(N^2) O(1)
class Solution {
    public int countCompleteDayPairs(int[] hours) {
        int cnt = 0, n = hours.length;

        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((hours[i] + hours[j]) % 24 == 0) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
}

// 2ms 100.00% 42.4MB 50.00%
// hash map
// O(N) O(N)
class Solution {
    public int countCompleteDayPairs(int[] hours) {
        int cnt = 0, n = hours.length;
        Map<Integer, Integer> tsCntMap = new HashMap<>();

        for (int hr : hours) {
            hr %= 24;
            cnt += tsCntMap.getOrDefault((24 - hr) % 24, 0);
            tsCntMap.put(hr, tsCntMap.getOrDefault(hr, 0) + 1); 
            // System.out.printf("hr: %d, cnt: %d\n\t", hr, cnt);
            // System.out.println(tsCntMap);
        }

        return cnt;
    }
}
