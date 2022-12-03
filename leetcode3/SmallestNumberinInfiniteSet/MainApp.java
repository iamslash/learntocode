// Copyright (C) 2022 by iamslash

import java.util.*;

// 23ms 74.32% 54.6MB 49.55%
// heap
// O(NlgN) O(N)
class SmallestInfiniteSet {
    private int minNum = 1;
    private Queue<Integer> pq = new PriorityQueue<>();

    public int popSmallest() {
        int rst = minNum;
        // Get minimum number
        if (!pq.isEmpty() && pq.peek() < rst) {
            rst = pq.poll();
        } else {
            minNum++;
        }
        // Resolve pq
        while (!pq.isEmpty() && pq.peek() == rst) {
            pq.poll();
        }
        return rst;
    }
    
    public void addBack(int num) {
        if (num < minNum) {
            pq.offer(num);
        }
    }
}
