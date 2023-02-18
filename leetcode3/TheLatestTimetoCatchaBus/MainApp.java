// Copyright (C) 2023 by iamslash

import java.util.*;

//   capacity: 2
//      buses: 10 20 30
// passengers: 4 11 13 19 21 25 26

// Idea: greedy, sort, two pointers
//
//         i: buses index
//         j: passengers index
// personSet: passengers who has depart
// The ans should be the last one possible.
// Consider passengers[j-1] as candidate on loop
// Consider buses[i] as candidate on loop

// 49ms 37.25% 64.9MB 34.18%
// greedy, sort, two pointers
// O(N) O(N)
class Solution {
    public int latestTimeCatchTheBus(int[] buses, int[] passengers, int capa) {
        Arrays.sort(buses);
        Arrays.sort(passengers);
        Set<Integer> personSet = new HashSet<>();
        int ans = 0, n = buses.length, m = passengers.length;
        // i for bus, j for person
        for (int i = 0, j = 0; i < n; ++i) {
            int cnt = 0;
            // Update ans with passengers[j-1]
            while (j < m && cnt < capa &&
                   passengers[j] <= buses[i]) {
                if (!personSet.contains(passengers[j] - 1)) {
                    ans = passengers[j] - 1;
                }
                personSet.add(passengers[j]);
                cnt++;
                j++;
            }
            // Update ans with buses[i]
            if (cnt < capa && !personSet.contains(buses[i])) {
                ans = buses[i];
            }
        }
        return ans;
    }
}
