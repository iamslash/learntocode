// Copyright (C) 2021 by iamslash

import java.util.*;

// 1ms 88.67% 39MB 72.84%
// brute force
// O(N) O(1)
class Solution {
    public int finalValueAfterOperations(String[] operations) {
        int ans = 0;
        for (String op : operations) {
            if (op.equals("++X") || op.equals("X++")) {
                ans++;
            } else {
                ans--;
            }
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
