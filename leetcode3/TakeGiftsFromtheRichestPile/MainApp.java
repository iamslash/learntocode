// Copyright (C) 2023 by iamslash

import java.util.*;

// 5ms 100.00% 41.9MB 100.00%
// heap
// O(NlgN) O(N)
class Solution {
    public long pickGifts(int[] gifts, int k) {
        Queue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        for (int gift : gifts) {
            pq.offer(gift);
        }
        while (k-- > 0) {
            int top = pq.poll();
            pq.offer((int)(Math.sqrt(top)));
        }
        long sum = 0;
        while (!pq.isEmpty()) {
            sum += pq.poll();
        }
        return sum;
    }
}
