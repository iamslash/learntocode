// Copyright (C) 2022 by iamslash

import java.util.*;


//                i
//      props: 10,4 10,7 7,5 7,9 7,10 6,9 
// maxDefence: 7
//        cnt: 1

// 144ms 66.92% 156.6MB 16.08%
// sort against each other
// O(NlgN) O(1)
class Solution {
    private void dump(int[][] A) {
        for (int[] aa : A) {
            System.out.printf("%d,%d ", aa[0], aa[1]);
        }
        System.out.println();
    }
    public int numberOfWeakCharacters(int[][] props) {
        Arrays.sort(props, (a, b) -> a[0] == b[0] ? a[1] - b[1] : b[0] - a[0]);
        // dump(props);
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
