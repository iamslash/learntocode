// Copyright (C) 2024 by iamslash

import java.util.*;

// Idea: math
// 
// 115 is 75 + 40 which means 1 x and 4 y
// turns = min(x, y / 4)
// If turns % 2 == 1, Alice wins
// If turns % 2 == 0, Bob wins

// 0ms 100.00% 41.4MB 77.03%
// math
// O(1) O(1)
class Solution {
    public String losingPlayer(int x, int y) {
        int turns = Math.min(x, y / 4);

        if (turns % 2 == 1) {
            return "Alice";
        }
        
        return "Bob";
    }
}
