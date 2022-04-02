// Copyright (C) 2022 by iamslash

import java.util.*;

// 1ms 98.73% 39.7MB 99.79%
// deque
//     hit: O(1) O(N)
// getHits: O(1) O(N)
class HitCounter {
    private Deque<Integer> deq = new ArrayDeque<>();
    private void clean(int ts) {
        int i = ts - 300;
        while (deq.size() > 0 && deq.peekFirst() <= i) {
            deq.removeFirst();
        }
    }
    public void hit(int ts) {
        deq.addLast(ts);
        clean(ts);
    }
    
    public int getHits(int ts) {
        clean(ts);
        return deq.size();
    }
}
