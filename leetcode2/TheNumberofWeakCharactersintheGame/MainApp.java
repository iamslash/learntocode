// Copyright (C) 2023 by iamslash

import java.util.*;

//          
// props: 3,6 5,5 6,3
//              i
//        6,3 6,4 3,6
//              i
//        6,3 5,5 3,6

// 176ms 6.75% 100.9MB 71.57%
// sort
// O(NlgN) O(1)
class Solution {
    public int numberOfWeakCharacters(int[][] props) {
        Arrays.sort(props, (a, b) -> a[0] == b[0] ? a[1] - b[1] : b[0] - a[0]);
        int n = props.length, cnt = 0, maxDefence = 0;
        for (int i = 0; i < n; ++i) {
            if (props[i][1] < maxDefence) {
                cnt++;
            }
            maxDefence = Math.max(maxDefence, props[i][1]);
        }
        return cnt;
    }
}
