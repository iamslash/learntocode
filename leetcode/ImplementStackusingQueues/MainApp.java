// Copyright (C) 2024 by iamslash

import java.util.*;


// Idea: queue
//
// Push x to queue.
// Rotate n - 1 times.
//
// push 1: 1
//
// push 2: 1 2
//         2 1

// push 3: 2 1 3
//         1 3 2
//         3 2 1

// push 4: 3 2 1 4
//         2 1 4 3
//         1 4 3 2
//         4 3 2 1
        
// push 5: 4 3 2 1 5
//         3 2 1 5 4
//         2 1 5 4 3
//         1 5 4 3 2
//         5 4 3 2 1        

// 0ms 100.00% 41.1MB 46.29%
// queue
// push: O(N) O(N)
class MyStack {

    private Queue<Integer> queue = new LinkedList<>();
    
    public void push(int x) {
        queue.offer(x);
        for (int i = 1; i < queue.size(); ++i) {
            queue.offer(queue.poll());
        }
    }
    
    public int pop() {
        return queue.poll();
    }
    
    public int top() {
        return queue.peek();
    }
    
    public boolean empty() {
        return queue.isEmpty();
    }
}
