// Copyright (C) 2022 by iamslash

import java.util.*;

//     cap: 2
//           i
//   buses: 10 20
//    pass: 2 17 18 19
//          j
//     cnt: 1
//   tsSet:
//     ans: 1

class Solution {
    public int latestTimeCatchTheBus(int[] buses, int[] passengers, int capacity) {
        Arrays.sort(buses);
        Arrays.sort(passengers);
        Set<Integer> tsSet = new HashSet<>();
        int ans = 0, n = buses.length, m = passengers.length;
        for (int i = 0, j = 0; i < n; ++i) {
            int cnt = 0;
            while (j < m && cnt < capacity && buses[i] >= passengers[j]) {
                if (!tsSet.contains(passengers[j] - 1)) {
                    ans = passengers[j] - 1;
                }
                tsSet.add(passengers[j]);
                cnt++;
                j++;
            }
            if (cnt < capacity && !tsSet.contains(buses[i])) {
                ans = buses[i];
            }
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
