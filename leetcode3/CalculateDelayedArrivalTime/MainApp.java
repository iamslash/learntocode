// Copyright (C) 2023 by iamslash

import java.util.*;

// 0ms 100.00% 39.4MB 83.33%
// math
// O(1) O(1)
class Solution {
    public int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        return (arrivalTime + delayedTime) % 24;
    }
}
