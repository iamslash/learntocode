// Copyright (C) 2022 by iamslash

import java.util.*;

//        i
// time: 30 20 150 100 40
//        

// Time Limit Exceeded
// brute force
// O(N^2) O(1)
class Solution {
    public int numPairsDivisibleBy60(int[] time) {
        int n = time.length, cnt = 0;
        for (int i = 0; i < n-1; ++i) {
            for (int j = i+1; j < n; ++j) {
                if ((time[i] + time[j]) % 60 == 0) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
}

// two sum
// O(N) O(N)
class Solution {
    public int numPairsDivisibleBy60(int[] time) {
        int cnts[] = new int[60];
        int ans = 0;
    }
}
