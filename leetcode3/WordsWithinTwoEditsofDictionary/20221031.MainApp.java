// Copyright (C) 2022 by iamslash

import java.util.*;

// 29ms 20.00% 43.4MB 60.00%
// brute foce
// O(QD) O(Q)
class Solution {
    private int diff(String a, String b) {
        int cnt = 0, n = a.length();
        for (int i = 0; i < n; ++i) {
            if (a.charAt(i) != b.charAt(i)) {
                cnt++;
            }
        }
        return cnt;
    }
    public List<String> twoEditWords(String[] queries, String[] dicts) {
        List<String> ans = new ArrayList<>();
        for (String qry : queries) {
            for (String dic : dicts) {
                if (diff(qry, dic) <= 2) {
                    ans.add(qry);
                    break;
                }
            }
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
