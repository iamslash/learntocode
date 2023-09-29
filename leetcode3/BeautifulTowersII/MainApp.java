// Copyright (C) 2023 by iamslash

import java.util.*;

// 92ms 48.53% 62.1MB 66.91%
// mono stack
// O(N) O(N)
class Solution {
    public long maximumSumOfHeights(List<Integer> maxHeights) {
        int n = maxHeights.size();
        long[] lefts = new long[n];
        Stack<Integer> stck = new Stack<>();
        stck.push(-1);
        long ans = 0, sum = 0;
        // Update lefts
        for (int i = 0; i < n; ++i) {
            while (stck.size() > 1 &&
                   maxHeights.get(stck.peek()) > maxHeights.get(i)) {
                int j = stck.pop();
                sum -= 1L * (j - stck.peek()) * maxHeights.get(j);
            }
            sum += 1L * (i - stck.peek()) * maxHeights.get(i);
            stck.push(i);
            lefts[i] = sum;
        }
        // Update ans
        stck.clear();
        stck.push(n);
        sum = 0;
        for (int i = n - 1; i >= 0; --i) {
            while (stck.size() > 1 &&
                   maxHeights.get(stck.peek()) > maxHeights.get(i)) {
                int j = stck.pop();
                sum -= 1L * -(j - stck.peek()) * maxHeights.get(j);
            }
            sum += 1L * -(i - stck.peek()) * maxHeights.get(i);
            stck.push(i);
            ans = Math.max(ans, lefts[i] + sum - maxHeights.get(i));
        }
        return ans;
    }
}
