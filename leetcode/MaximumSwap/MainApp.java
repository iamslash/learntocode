// Copyright (C) 2024 by iamslash

import java.util.*;

// Idea: hash map
//
// convert `num` to `char[] digits`.
// `int[] lastIdxs` is last indices of digit 0 ~ 9.
// for (int i = 0; i < n; ++i)
//   for (int d = 9; d > digits[i]; --d)
//     if (lastIdxs[d] > i)
//       swap and return digits after converting

// 0ms 100.00% 40.6MB 21.62%
// hash map
// O(N) O(N)
class Solution {
    public int maximumSwap(int num) {
        char[] digits = Integer.toString(num).toCharArray();
        int[] lastIdxs = new int[10];
        int n = digits.length;

        for (int i = 0; i < n; ++i) {
            lastIdxs[digits[i] - '0'] = i;
        }

        for (int i = 0; i < n; ++i) {
            for (int d = 9; d > digits[i] - '0'; --d) {
                if (lastIdxs[d] > i) {
                    char tmp = digits[i];
                    digits[i] = digits[lastIdxs[d]];
                    digits[lastIdxs[d]] = tmp;

                    return Integer.parseInt(new String(digits));
                }
            }
        }

        return num;
    }
}
