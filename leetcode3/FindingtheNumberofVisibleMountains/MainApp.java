// Copyright (C) 2022 by iamslash

import java.util.*;

// 99ms 100.00% 155.1MB 100.00%
// mono stack
// O(N) O(N)
class Solution {
    public int visibleMountains(int[][] peaks) {
        Arrays.sort(peaks, (a, b) -> a[0] != b[0] ? a[0] - b[0]: a[1] - b[1]);
        int n = peaks.length;
        Deque<Integer> stck = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            int x = peaks[i][0], y = peaks[i][1];
            // Skip the same point
            if (i > 0 && peaks[i-1][0] == x && peaks[i-1][1] == y) {
                if (!stck.isEmpty() && stck.peekLast() == i - 1) {
                    stck.pollLast();
                }
                continue;
            }
            // Remove previous hidden points
            while (!stck.isEmpty() && y - peaks[stck.peekLast()][1] >=
                   x - peaks[stck.peekLast()][0]) {
                stck.pollLast();
            }
            // Skip current hidden point
            if (!stck.isEmpty() && peaks[stck.peekLast()][1] - y >=
                x - peaks[stck.peekLast()][0]) {
                continue;
            }
            stck.offerLast(i);
        }
        return stck.size();
    }
}
