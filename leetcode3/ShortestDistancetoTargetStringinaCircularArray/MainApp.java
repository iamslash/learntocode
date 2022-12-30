// Copyright (C) 2022 by iamslash

import java.util.*;

//           s
//  words: a b c d e
//                 i
//               j
// target: a


//           s
//  words: a b c d
//               i
//               j
// target: a

//               i
//  words: hello i am leetcode hello
// target: hello


// 0ms 100.00% 42.6MB 83.75%
// math
// O(N) O(1)
class Solution {
    public int closetTarget(String[] words, String target, int startIndex) {
        int n = words.length, half = n / 2, i = 0;
        while (i <= half) {
            int leftIndex = (startIndex - i + n) % n;
            int rightIndex = (startIndex + i) % n;
            if (words[leftIndex].equals(target) ||
                words[rightIndex].equals(target)) {
                return i;
            }
            i++;
        }
        return -1;
    }
}

