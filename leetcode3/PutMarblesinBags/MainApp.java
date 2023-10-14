// Copyright (C) 2023 by iamslash

import java.util.*;

// Idea: sort
//
//       k: 2
// weights: a b c d
//          a | b c d    a + a + b + d
//          a b | c d    a + b + c + d
//          a b c | d    a + c + d + d
// Consider all cases, max - min
//          (a + a + b + d) - (a + b + c + d) = (a + b) - (b + c)
//          (a + a + b + d) - (a + c + d + d) = (a + b) - (c + d)
//          (a + b + c + d) - (a + a + b + d) = (b + c) - (a + b)
//          (a + b + c + d) - (a + c + d + d) = (b + c) - (c + d)
//          (a + c + d + d) - (a + a + b + d) = (c + d) - (a + b)
//          (a + c + d + d) - (a + b + c + d) = (c + d) - (b + c)
// When we max - min, there is no a, d.
// Build edgeSums[n - 1]
// Sort edgeSums[]
// sum of edgeSums[n-k+1..n) - sum of edgeSums[0..k-1)

// 35ms 34.98% 59.2MB 47.98%
// sort
// O(NlgN) O(N)
class Solution {
    public long putMarbles(int[] weights, int k) {
        int n = weights.length - 1;
        long edgeSums[] = new long[n], ans = 0;
        for (int i = 0; i < n; ++i) {
            edgeSums[i] = weights[i] + weights[i + 1];
        }
        Arrays.sort(edgeSums);
        for (int i = 0; i < k - 1; ++i) {
            ans += edgeSums[n - 1 - i] - edgeSums[i];
        }
        return ans;
    }
}

// 192ms 18.39% 56.5MB 73.54%
// heap
// O(NlgN) O(N)
class Solution {
    public long putMarbles(int[] weights, int k) {
        int n = weights.length - 1;
        Integer[] edgeSums = new Integer[n];
        for (int i = 0; i < n; i++) {
            edgeSums[i] = weights[i] + weights[i + 1];
        }
        
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a);
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        for (int sum : edgeSums) {
            maxHeap.add(sum);
            minHeap.add(sum);
        }
        
        long maxScore = 0, minScore = 0;
        while (k-- > 1) {
            maxScore += maxHeap.poll();
            minScore += minHeap.poll();
        }
        return maxScore - minScore;
    }
}
