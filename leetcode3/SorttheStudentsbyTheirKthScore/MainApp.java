// Copyright (C) 2023 by iamslash

import java.util.*;

// 5ms 33.58% 76.5MB 22.15%
// sort
// O(NlgN) O(1)
// N: number of students
class Solution {
    public int[][] sortTheStudents(int[][] score, int k) {
        Arrays.sort(score, (a, b) -> b[k] - a[k]);
        return score;
    }
}
