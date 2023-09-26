// Copyright (C) 2023 by iamslash

import java.util.*;

// 47ms 79.44% 42.8MB 98.05%
// brute force
// O(N^2) O(1)
class Solution {
    public long maximumSumOfHeights(List<Integer> maxHeights) {
        int n = maxHeights.size();
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            long sum = maxHeights.get(i), bnd = sum;
            for (int j = i - 1; j >= 0; --j) {
                bnd = Math.min(bnd, maxHeights.get(j));
                sum += bnd;
            }
            bnd = maxHeights.get(i);
            for (int j = i + 1; j < n; ++j) {
                bnd = Math.min(bnd, maxHeights.get(j));
                sum += bnd;
            }
            ans = Math.max(ans, sum);
        }
        return ans;
    }
}

// 10ms 96.65% 43.6MB 44.40%
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
