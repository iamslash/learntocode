// Copyright (C) 2025 by iamslash

import java.util.*;

// numbers:
// 001
// 00153
// 007
// 15

// 3ms 100.005 43.12MB 100.00%
// sort
// O(NlgN) O(1)
class Solution {
    
    public boolean phonePrefix(String[] numbers) {
        int n = numbers.length;

        Arrays.sort(numbers);
        
        for (int i = 0; i < n - 1; ++i) {
            if (numbers[i + 1].startsWith(numbers[i])) {
                return false;
            }
        }

        return true;
    }
}
