// Copyright (C) 2022 by iamslash

import java.util.*;


//       i
//    s: ( )
// stck: (

// 1ms 99.41% 42.3MB 21.24%
// stack
// O(N) O(N)
class Solution {
    public boolean isValid(String s) {
        Deque<Character> deq = new ArrayDeque<>();
        for (char c : s.toCharArray()) {
            if (c == ')') {
                if (deq.isEmpty() || deq.peekLast() != '(') {
                    return false;
                }
                deq.removeLast();
            } else if (c == '}') {
                if (deq.isEmpty() || deq.peekLast() != '{') {
                    return false;
                }
                deq.removeLast();
            } else if (c == ']') {
                if (deq.isEmpty() || deq.peekLast() != '[') {
                    return false;
                }
                deq.removeLast();
            } else {
                deq.addLast(c);
            }
        }
        return deq.size() == 0;
    }
}

//      i
// s: ( { ) )
//        c
//          j

// 1ms 99.41% 42.4MB 15.45%
// two pointers
// O(N) O(1)
class Solution {
    public boolean isValid(String s) {
        char[] stck = s.toCharArray();
        int i = -1, j = 0, n = s.length();
        while (j < n) {
            char c = stck[j++];
            if (c == '{' || c == '(' || c == '[') {
                stck[++i] = c;
            } else if (i >= 0 && c == '}' && stck[i] == '{') {
                i--;
            } else if (i >= 0 && c == ')' && stck[i] == '(') {
                i--;
            } else if (i >= 0 && c == ']' && stck[i] == '[') {
                i--;
            } else {
                return false;
            }
        }
        return i == -1;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
