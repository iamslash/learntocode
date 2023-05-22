// Copyright (C) 2023 by iamslash

import java.util.*;

//              i
//    s: ABFCACDB
// stck: FC

// // 7ms 85.71% 43.4MB 14.29%
// // stack
// // O(N) O(N)
// class Solution {
//     public int minLength(String s) {
//         int n = s.length();
//         Stack<Character> stck = new Stack<>();
//         for (int i = 0; i < n; ++i) {
//             if (stck.size() > 0 && ((s.charAt(i) == 'B' && stck.peek() == 'A') ||
//                                     (s.charAt(i) == 'D' && stck.peek() == 'C'))) {                                    
//                 stck.pop();
//             } else {
//                 stck.push(s.charAt(i));
//             }
//         }
//         return stck.size();
//     }
// }

// 4ms 100.00% 43.9MB 14.29%
// deque
// O(N) O(N)
class Solution {
    public int minLength(String s) {
        int n = s.length();
        Deque<Character> deq = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            if (deq.size() > 0 &&
                ((s.charAt(i) == 'B' && deq.peekLast() == 'A') ||
                 (s.charAt(i) == 'D' && deq.peekLast() == 'C'))) {
                deq.removeLast();
            } else {
                deq.addLast(s.charAt(i));
            }
        }
        return deq.size();
    }
}
