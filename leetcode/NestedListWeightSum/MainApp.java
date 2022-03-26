// Copyright (C) 2022 by iamslash

import java.util.*;

public interface NestedInteger {
    public NestedInteger();
    public NestedInteger(int value);
    public boolean isInteger();
    public Integer getInteger();
    public void setInteger(int value);
    public void add(NestedInteger ni);
    public List<NestedInteger> getList();
}

// 1ms 82.67% 41.6MB 55.76%
// DFS
// O(N) O(N)
class Solution {
    private int dfs(List<NestedInteger> l, int depth) {
        int sum = 0;
        for (NestedInteger ni : l) {
            if (ni.isInteger()) {
                sum += ni.getInteger() * depth;
            } else {
                sum += dfs(ni.getList(), depth+1);
            }
        }
        return sum;
    }
    public int depthSum(List<NestedInteger> nestedList) {
        return dfs(nestedList, 1);
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
