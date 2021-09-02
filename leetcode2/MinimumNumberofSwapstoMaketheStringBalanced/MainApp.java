// Copyright (C) 2021 by iamslash

import java.util.*;

//                ans  stack    size
// s: ][          1    [        1
// s: ]][[        1    [[       2
// s: ]]][[[      2    [[[      3
// s: ]]]][[[[    2    [[[[     4
// s: ]]]]][[[[[  3    [[[[[    5
// ...
// ans = (stack.size() + 1) / 2

// 146ms 6.14% 120.7MB 5.24
// stack
// O(N) O(N)
class Solution {
    public int minSwaps(String s) {
        Deque<Integer> deq = new ArrayDeque<>();
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (c == '[') {
                deq.addLast(i);
            } else if (deq.size() > 0) {
                deq.pollLast();
            }
        }
        return (deq.size()+1) / 2;
    }
}

// 26ms 51.09% 71.7MB 23.99%
// linear traversal
// O(N) O(1)
class Solution {
    public int minSwaps(String s) {
        int cnt = 0;
        for (char c : s.toCharArray()) {
            if (c == '[') {
                cnt++;
            } else if (cnt > 0) {
                cnt--;
            }
        }
        return (cnt + 1) / 2;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
