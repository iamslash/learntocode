// Copyright (C) 2022 by iamslash

import java.util.*;

interface NestedInteger {
    boolean isInteger();
    Integer getInteger();
    void setInteger(int value);
    void add(NestedInteger ni);
    List<NestedInteger> getList();
}

// nl: [[1,1],2,[1,1]]

// 1ms 86.65% 41.9MB 32.76%
// BFS
// O(N) O(N)
class Solution {
    public int depthSumInverse(List<NestedInteger> nestedList) {
        int locSum = 0, glbSum = 0;
        while (!nestedList.isEmpty()) {
            List<NestedInteger> tmpList = nestedList;
            nestedList = new ArrayList<>();
            for (NestedInteger ni : tmpList) {
                if (ni.isInteger()) {
                    locSum += ni.getInteger();
                } else {
                    nestedList.addAll(ni.getList());
                }
            }
            glbSum += locSum;
        }
        return glbSum;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
