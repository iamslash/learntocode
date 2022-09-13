// Copyright (C) 2022 by iamslash

import java.util.*;

// 17ms 92.59% 47.9MB 87.41%
// bit manipulation
// O(N) O(1)
class Solution {
    public int partitionString(String s) {
        int freqBm = 0, partCnt = 1;
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            boolean isExist = (freqBm & (1 << c - 'a')) > 0; 
            if (isExist) {
                partCnt++;
                freqBm = 0;
            }
            freqBm |= (1 << c - 'a');
        }
        return partCnt;
    }
}
