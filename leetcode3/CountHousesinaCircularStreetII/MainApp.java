// Copyright (C) 2023 by iamslash

import java.util.*;

interface Street {
    void closeDoor();
    boolean isDoorOpen();
    void moveRight();
}

// f
//   i
// 1 0 1 0 1 1
//  
// pos: 0

// 16ms 100.00% 56.4MB 53.49%
// greedy
// O(N) O(1)
class Solution {
    public int houseCount(Street street, int k) {
        while (!street.isDoorOpen()) {
            street.moveRight();
        }
        street.moveRight();
        int pos = 0;
        for (int i = 0; i < k; ++i) {
            if (street.isDoorOpen()) {
                street.closeDoor();
                pos = i;
            }
            street.moveRight();
        }
        return pos + 1;
    }
}
