// Copyright (C) 2021 by iamslash

import java.util.*;

//    cap: 5
//               i
// plants: 2 2 3 3
//  avail: 3 1 2 2 
//   step: 1 2 7 14

// 1ms 50.55% 40.1MB 23.17%
// brute force
// O(N) O(1)
class Solution {
    public int wateringPlants(int[] plants, int capacity) {
        int step = 0, avail = capacity;
        for (int i = 0; i < plants.length; ++i) {
            if (avail < plants[i]) {
                step += i * 2;
                avail = capacity;
            }
            step++;
            avail -= plants[i];
        }
        return step;
    }
}
