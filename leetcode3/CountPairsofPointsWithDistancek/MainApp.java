// Copyright (C) 2023 by iamslash

import java.util.*;

// // Time Limit Exceeded
// // brute force
// // O(N^2) O(1)
// class Solution {
//     public int countPairs(List<List<Integer>> coordinates, int k) {
//         int cnt = 0, n = coordinates.size();
//         for (int i = 0; i < n; ++i) {
//             int x1 = coordinates.get(i).get(0);
//             int y1 = coordinates.get(i).get(1);
//             for (int j = i + 1; j < n; ++j) {
//                 int x2 = coordinates.get(j).get(0);
//                 int y2 = coordinates.get(j).get(1);
//                 if ((x1 ^ x2) + (y1 ^ y2) == k) {
//                     cnt++;
//                 }
//             }
//         }
//         return cnt;
//     }
// }

// k: 5
// 1,2 4,2 1,3 5,2
// coordMap

// Idea: hash map
//
// x1 ^ x2 + y1 ^ y2 = k
// if        x1 ^ x2 = val        
// then      y1 ^ y2 = k - val   
// x2 = val ^ x1
// y2 = (k - val) ^ y1
//
// val is [0..k]
// According to constraints, 0 <= k <= 100.
//
// 108ms 72.27% 76.9MB 5.02%
// hash map
// O(N) O(N)
class Solution {
    public int countPairs(List<List<Integer>> coordinates, int k) {
        // {x, {y, cnt}}
        Map<Integer, Map<Integer, Integer>> cntMap = new HashMap<>();
        int cnt = 0;
        for (List<Integer> coord : coordinates) {
            int x1 = coord.get(0), y1 = coord.get(1);
            for (int xxor = 0; xxor <= k; ++xxor) {
                int x2 = x1 ^ xxor, y2 = y1 ^ (k - xxor);
                if (cntMap.containsKey(x2) &&
                    cntMap.get(x2).containsKey(y2)) {
                    cnt += cntMap.get(x2).get(y2);
                }
            }
            cntMap.putIfAbsent(x1, new HashMap<>());
            cntMap.get(x1).put(y1, cntMap.get(x1).getOrDefault(y1, 0) + 1);
        }
        return cnt;
    }
}
