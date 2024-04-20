// Copyright (C) 2024 by iamslash

import java.util.*;

// 5ms 96.85% 45.1MB 10.07%
// stack
// O(N) O(N)
class Solution {
    public int evalRPN(String[] tokens) {
        Deque<Integer> deq = new ArrayDeque<>();

        int a = 0, b = 0;

        for (String token : tokens) {
            if (token.equals("+")) {
                b = deq.removeLast();
                a = deq.removeLast();
                deq.addLast(a + b);
            } else if (token.equals("-")) {
                b = deq.removeLast();
                a = deq.removeLast();
                deq.addLast(a - b);
            } else if (token.equals("*")) {
                b = deq.removeLast();
                a = deq.removeLast();
                deq.addLast(a * b);
            } else if (token.equals("/")) {
                b = deq.removeLast();
                a = deq.removeLast();
                deq.addLast(a / b);
            } else {
                deq.addLast(Integer.valueOf(token));
            }
        }

        return deq.peek();
    }
}
