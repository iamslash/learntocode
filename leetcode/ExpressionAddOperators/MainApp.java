// Copyright (C) 2021 by iamslash

import java.util.*;

// 163ms 13.60% 114.1MB 5.06%
// backtracking
// O(3^N) O(N)
class Solution {
    private void dfs(List<String> rst,
                     String path,
                     String num,
                     int target,
                     int pos,
                     long eval,
                     long multed) {
        // base
        if (pos == num.length()) {
            if (target == eval) {
                rst.add(path);
            }
            return;
        }
        // recursion
        for (int i = pos; i < num.length(); ++i) {
            if (i != pos && num.charAt(pos) == '0') {
                break;
            }
            long cur = Long.parseLong(num.substring(pos, i + 1));
            if (pos == 0) {
                dfs(rst, path + cur, num, target, i + 1, cur, cur);
            } else {
                dfs(rst, path + "+" + cur, num, target, i+1, eval + cur, cur);
                dfs(rst, path + "-" + cur, num, target, i+1, eval - cur, -cur);
                dfs(rst, path + "*" + cur, num, target, i+1, eval - multed + multed * cur, multed * cur);
            }
        }
    }
                     
    public List<String> addOperators(String num, int target) {
        List<String> ans = new ArrayList<>();
        if (num == null || num.length() == 0) {
            return ans;
        }
        dfs(ans, "", num, target, 0, 0, 0);
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
