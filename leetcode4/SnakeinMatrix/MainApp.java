// Copyright (C) 2024 by iamslash

import java.util.*;

// 2ms 97.42% 44.3MB 74.21%
// brute force
// O(N) O(1)
class Solution {
    public int finalPositionOfSnake(int n, List<String> commands) {
        int pos = 0;
        
        for (String cmd : commands) {
            if (cmd.equals("UP")) {
                pos -= n;
            } else if (cmd.equals("RIGHT")) {
                pos += 1;
            } else if (cmd.equals("DOWN")) {
                pos += n;
            } else {
                pos -= 1;
            }
        }

        return pos;
    }
}
