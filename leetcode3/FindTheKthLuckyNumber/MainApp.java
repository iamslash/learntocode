// Copyright (C) 2023 by iamslash

import java.util.*;

// // Time Limit Exceeded
// // Input: 50099
// //
// // bfs
// // O(N) O(N)
// class Solution {
//     public String kthLuckyNumber(int k) {
//         Queue<Long> q = new LinkedList<>();
//         q.offer(0L);
//         int step = 0;
//         while (!q.isEmpty()) {
//             long num = q.poll();
//             if (step == k) {
//                 return String.valueOf(num);
//             }
//             q.offer(num * 10L + 4);
//             q.offer(num * 10L + 7);
//             step++;
//         }
//         return "";
//     }
// }

// Idea: bit manipulation
//
//    0
//    1
//   10 4
//   11 7
//  100 44
//  101 47
//  110 74
//  111 77
// 1000 444
// 1001 447

// 6ms 77.59% 43.2MB 100.00%
// bit manipulation
// O(N) O(1)
class Solution {
    public String kthLuckyNumber(int k) {
        StringBuilder sb = new StringBuilder();
        for (int i = k + 1; i > 1; i /= 2) {
            sb.append((i & 1) == 1 ? '7' : '4');
        }
        // System.out.println(sb);
        return sb.reverse().toString();
    }
}
 
