// Copyright (C) 2026 by iamslash

//       i
//    s: x y z
// half: 1
//
//       i
//    s: a b c d
// half: 2

// 1ms 99.80% 44.64MB 73.76%
// linear traversal
// O(N) O(N)
class Solution {
    public String reversePrefix(String s, int k) {
        int n = s.length();
        char[] chars = s.toCharArray();

        int half = k / 2;
        for (int i = 0; i < half; ++i) {
            char tmp = chars[i];
            chars[i] = chars[k - i - 1];
            chars[k - i - 1] = tmp;
        }

        return String.valueOf(chars);
    }
}
