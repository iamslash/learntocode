// Copyright (C) 2023 by iamslash

import java.util.*;

//          
// props: 3,6 5,5 6,3
//              i
//        6,3 6,4 3,6
//              i
//        6,3 5,5 3,6

// // 176ms 6.75% 100.9MB 71.57%
// // sort
// // O(NlgN) O(1)
// class Solution {
//     public int numberOfWeakCharacters(int[][] props) {
//         Arrays.sort(props, (a, b) -> a[0] == b[0] ? a[1] - b[1] : b[0] - a[0]);
//         int n = props.length, cnt = 0, maxDefence = 0;
//         for (int i = 0; i < n; ++i) {
//             if (props[i][1] < maxDefence) {
//                 cnt++;
//             }
//             maxDefence = Math.max(maxDefence, props[i][1]);
//         }
//         return cnt;
//     }
// }


// Idea: hash map
//
// Let's think about 2 dimension graph.
// y is max defence (maxY[]).
// x is attack.
// If we precalculate maxY for attack [0..100001],
// we can get max defence maxY[x + 1] for x.
// x + 1 for same x values.
//
// |....    
// |    .
// |     .
//  ------
//

// props: 3,6 5,5 6,3

// props: 1,1 1,2 2,1 2,2
//
// |
// |
// |..
// |..
//  --

// 9ms 89.32% 106.3MB 5.10%
// hash map
// O(N) O(1)
class Solution {
    public int numberOfWeakCharacters(int[][] props) {
        int[] maxY = new int[100_002];
        int cnt = 0;
        for (int[] prop : props) {
            int x = prop[0], y = prop[1];
            maxY[x] = Math.max(maxY[x], y);
        }
        for (int x = 100_000; x >= 0; --x) {
            maxY[x] = Math.max(maxY[x], maxY[x + 1]);
        }
        for (int[] prop : props) {
            int x = prop[0], y = prop[1];
            // maxY[x + 1] for same x values.
            // ex) 1,1 1,2
            if (y < maxY[x + 1]) {
                cnt++;
            }
        }
        return cnt;
    }
}
