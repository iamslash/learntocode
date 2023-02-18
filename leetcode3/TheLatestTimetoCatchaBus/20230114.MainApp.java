// Copyright (C) 2022 by iamslash

import java.util.*;

//     cap: 2
//           i
//   buses: 10 20
//    pass: 2 17 18 19
//          j
//     cnt: 1
//  pasSet:
//     ans: 1

// Idea: greedy
//
// i for buses
// j for passengers
// passengerSet for passengers who have gone
// The ans should be the last one possible.
// Consider passenger[j-1] as candidate on loops
// Consider buses[i] as candidate at last

// 50ms 41.96% 64.8MB 58.74%
// greedy, sort, two pointers
// O(N) O(N)
class Solution {
    public int latestTimeCatchTheBus(int[] buses, int[] passengers, int capacity) {
        Arrays.sort(buses);
        Arrays.sort(passengers);
        Set<Integer> passengerSet = new HashSet<>();
        int ans = 0, n = buses.length, m = passengers.length;
        // i for bus, j for passenger
        for (int i = 0, j = 0; i < n; ++i) {
            int cnt = 0;
            while (j < m && cnt < capacity && buses[i] >= passengers[j]) {
                if (!passengerSet.contains(passengers[j] - 1)) {
                    ans = passengers[j] - 1;
                }
                passengerSet.add(passengers[j]);
                cnt++;
                j++;
            }
            if (cnt < capacity && !passengerSet.contains(buses[i])) {
                ans = buses[i];
            }
        }
        return ans;
    }
}
