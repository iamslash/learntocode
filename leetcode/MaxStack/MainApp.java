// Copyright (C) 2022 by iamslash

import java.util.*;

// 15ms 91.77% 43.4MB 83.79%
// reverse index
//    push: O(NlgN) O(N)
//     pop: O(NlgN) O(N)
//     top: O(1)    O(N)
// peekMax: O(1)    O(N)
//  popMax: O(N)    O(N)
class MaxStack {
    private Deque<Integer> deq = new ArrayDeque<>();
    private Queue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
    public void push(int x) {
        deq.offerLast(x);
        pq.offer(x);
    }
    
    public int pop() {
        int e = deq.pollLast();
        pq.remove(e);
        return e;
    }
    
    public int top() {
        return deq.peekLast();
    }
    
    public int peekMax() {
        return pq.peek();
    }
    
    public int popMax() {
        int e = pq.poll();
        deq.removeLastOccurrence(e);
        return e;
    }
}
