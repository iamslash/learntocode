// Copyright (C) 2024 by iamslash

import java.util.*;

// 0ms 100.00% 42MB 63.96%
// math
// O(1) O(1)
class Solution {
    public boolean checkTwoChessboards(String coord1, String coord2) {
        int num1 = coord1.charAt(0) - 'a' + coord1.charAt(1) - '1';
        int num2 = coord2.charAt(0) - 'a' + coord2.charAt(1) - '1';
        return (num1 ^ num2) % 2 == 0;
    }
}
