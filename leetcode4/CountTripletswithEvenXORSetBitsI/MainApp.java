// Copyright (C) 2024 by iamslash

import java.util.*;

// // 495ms 25.53% 44.1MB 80.85%
// // brute force
// // O(ABC) O(1)
// class Solution {
//     private int getSetBitCnt(int num) {
//         int cnt = 0;

//         while (num > 0) {
//             if (num % 2 == 1) {
//                 cnt++;
//             }
//             num >>= 1;
//         }

//         return cnt;
//     }
//     public int tripletCount(int[] as, int[] bs, int[] cs) {
//         int cnt = 0;

//         for (int a : as) {
//             for (int b : bs) {
//                 for (int c : cs) {
//                     if (getSetBitCnt(a ^ b ^ c) % 2 == 0) {
//                         cnt++;
//                     }
//                 }
//             }
//         }

//         return cnt;
//     }
// }

// 1ms 100.00% 44.1MB 80.85%
// math
// O(N) O(1)
class Solution {
    private int[] getEvenOddCnt(int[] nums) {
        // cnts[0]: cnt of even set bit num
        // cnts[1]: cnt of odd set bit num
        int[] cnts = {0, 0}; 

        for (int num : nums) {

            int oneCnt = 0;
            while (num > 0) {
                if (num % 2 == 1) {
                    oneCnt++;
                }
                num >>= 1;
            }

            if (oneCnt % 2 == 0) {
                cnts[0]++;
            } else {
                cnts[1]++;
            }
            
        }

        return cnts;
    }
    public int tripletCount(int[] a, int[] b, int[] c) {
        int cnt = 0;

        int[] acnts = getEvenOddCnt(a);
        int[] bcnts = getEvenOddCnt(b);
        int[] ccnts = getEvenOddCnt(c);

        cnt += acnts[0] * bcnts[0] * ccnts[0];
        cnt += acnts[0] * bcnts[1] * ccnts[1];
        cnt += acnts[1] * bcnts[0] * ccnts[1];
        cnt += acnts[1] * bcnts[1] * ccnts[0];

        return cnt;
    }
}

// 1100
// 1100
// 0110
// ----
// 0110
