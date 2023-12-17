// Copyright (C) 2023 by iamslash

// 24 25  0  1  2
//  y  z  a  b  c

//  2  3  4  5  6
//  c  d  e  f  g

// 0ms 100.00% 40.3MB 77.33%
// math
// O(N) O(1)
class Solution {
    private int minDist(char a, char b) {
        if (a > b) {
            char t = a;
            a = b;
            b = t;
        }
        return Math.min(b - a, (a - 'a') + 26 - (b - 'a'));
    }
    public int minTimeToType(String word) {
        int cnt = 0;
        char from = 'a';
        for (char next : word.toCharArray()) {
            cnt += minDist(from, next) + 1;
            from = next;
        }
        return cnt;
    }
}
