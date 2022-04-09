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

// 1ms 87.28% 41.4MB 71.97%
// double DFS
// O(N) O(N)
class Solution {
    private int getMaxDepth(List<NestedInteger> nestedList) {
        int maxDepth = 0;
        // recursion
        for (NestedInteger ni : nestedList) {
            if (!ni.isInteger()) {
                maxDepth = Math.max(maxDepth, getMaxDepth(ni.getList()));
            }
        }
        return maxDepth + 1;
    }
    private int dfs(int maxDepth, List<NestedInteger> nestedList, int depth) {
        int sum = 0;
        // recursion
        for (NestedInteger ni : nestedList) {
            if (ni.isInteger()) {
                sum += (maxDepth - depth) * ni.getInteger();
            } else {
                sum += dfs(maxDepth, ni.getList(), depth + 1);
            }
        }
        return sum;
    }
    public int depthSumInverse(List<NestedInteger> nestedList) {
        int maxDepth = getMaxDepth(nestedList);
        return dfs(maxDepth, nestedList, 0);
    }
}

// 1ms 87.28% 41.6MB 53.95%
// DFS
// O(N) O(N)
class Solution {
    public int depthSumInverse(List<NestedInteger> nestedList) {
        int sum = 0, weightedSum = 0;
        while (!nestedList.isEmpty()) {
            List<NestedInteger> nextList = new ArrayList<>();
            for (NestedInteger ni : nestedList) {
                if (ni.isInteger()) {
                    sum += ni.getInteger();
                } else {
                    nextList.addAll(ni.getList());
                }
            }
            weightedSum += sum;
            nestedList = next;
        }
        return weightedSum;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
