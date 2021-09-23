// Copyright (C) 2021 by iamslash

import java.util.*;

// 0              0

// 2 1 2          8 
// 1 0 1
// 2 1 2

// 4 3 2 3 4      
// 3 2 1 2 3
// 2 1 0 1 2
// 3 2 1 2 3
// 4 3 2 3 4 

// 14ms 44.66% 35.5MB 94.96%
// math
// O(N) O(1)
class Solution {
    private long getApples(long n) {
        return 2 * (n - 1) * (2 * n * n - n);
    }
    public long minimumPerimeter(long neededApples) {
        long cnt = 0, len = 0;
        while (getApples(len) < neededApples) {
            len++;
        }
        return (len-1) * 8;
    }
}

// 0ms 100.00% 36.1MB 48.12%
// binary search
// O(lgN) O(1)
class Solution {
    private long getApples(long n) {
        return 2 * (n - 1) * (2 * n * n - n);
    }
    public long minimumPerimeter(long neededApples) {
        long lo = 0, hi = 100_000;
        while (lo < hi) {
            long mi = lo + (hi-lo)/2;
            if (getApples(mi) < neededApples) {
                lo = mi + 1;
            } else {
                hi = mi;
            }
        }
        return (lo-1)*8;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
