// Copyright (C) 2022 by iamslash

import java.util.*;

//                         i
//    time: 30 20 150 100 40
//
// remCnts: 20 30 40 
//           1  2  2
//
//     ans: 3

// // Time Limit Exceeded
// // brute force
// // O(N^2) O(1)
// class Solution {
//     public int numPairsDivisibleBy60(int[] time) {
//         int n = time.length, cnt = 0;
//         for (int i = 0; i < n-1; ++i) {
//             for (int j = i+1; j < n; ++j) {
//                 if ((time[i] + time[j]) % 60 == 0) {
//                     cnt++;
//                 }
//             }
//         }
//         return cnt;
//     }
// }

// 3ms 87.21% 54.7MB 9.15%
// two sum
// O(N) O(N)
class Solution {
    public int numPairsDivisibleBy60(int[] time) {
        int remCnts[] = new int[60];
        int ans = 0;
        for (int t : time) {
            int remA = t % 60;
            int remB = (60 - remA) % 60;
            ans += remCnts[remB];
            remCnts[remA]++;
        }
        return ans;
    }
}
