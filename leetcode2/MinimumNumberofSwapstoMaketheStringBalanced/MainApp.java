// Copyright (C) 2021 by iamslash

import java.util.*;

//    i
// s: ][][
//

//      i
// s: []][[]
//

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
        return deq.size();
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
