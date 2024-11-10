// Copyright (C) 2024 by iamslash

import java.util.*;

//
//  firstList: 0,2 5,10 13,23 24,25
//                                  i
// secondList: 1,5 8,12 15,24 25,26
//                                j
//
//     begMax:     1 5  8 13 15 24 25
//     endMin:     2 5 10 12 23 24 25
//                 . .  .     .  .  .

// 3ms 98.63% 45.4MB 81.15%
// two pointers
// O(N) O(N)
class Solution {
    public int[][] intervalIntersection(int[][] firstList, int[][] secondList) {
        List<int[]> mergedList = new ArrayList<>();
        int m = firstList.length, n = secondList.length;
        int i = 0, j = 0;

        while (i < m && j < n) {
            int[] first = firstList[i], second = secondList[j];
            int begMax = Math.max(first[0], second[0]);
            int endMin = Math.min(first[1], second[1]);
            if (begMax <= endMin) {
                mergedList.add(new int[]{begMax, endMin});
            }

            if (first[1] <= second[1]) {
                i++;
            } else {
                j++;
            }
        }

        return mergedList.toArray(new int[0][]);
    }
}
