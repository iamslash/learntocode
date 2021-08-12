// Copyright (C) 2021 by iamslash

// 14ms 26.11% 37.6MB 5.57%
// binary search
// O(lgN) O(1)
public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int lo = 1, hi = n, mi;
        while (lo < hi) {
            mi = lo + (hi-lo)/2;
            if (isBadVersion(mi)) {
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return lo;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
