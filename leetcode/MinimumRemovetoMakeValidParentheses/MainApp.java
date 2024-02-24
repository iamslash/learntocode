// Copyright (C) 2024 by iamslash

import java.util.*;

//           i
// s: lee(t(c)o)de)

// Idea: stack
// Prepare Stack<Integer>.
// Push unmatched idx of '(' to stack.
// Remove matched idx of '(' for ')'.
// Replace unmatched ')' with '*'.
// Replace idx in stack with '*'.
// Remove all '*' from the string.
//
// 16ms 81.28% 45.2MB 75.73%
// stack
// O(N) O(N)
class Solution {
    public String minRemoveToMakeValid(String s) {
        StringBuilder sb = new StringBuilder(s);
        Deque<Integer> deq = new ArrayDeque<>();
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (c == '(') {
                deq.addLast(i);
            } else if (c == ')') {
                if (!deq.isEmpty()) {
                    deq.removeLast();
                } else {
                    sb.setCharAt(i, '*');
                }
            }
        }
        while (!deq.isEmpty()) {
            sb.setCharAt(deq.removeLast(), '*');
        }
        String ans = sb.toString().replaceAll("\\*", "");
        return ans;
    }
}
