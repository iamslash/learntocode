// Copyright (C) 2022 by iamslash

import java.util.*;

// 252ms 8.34% 153.6MB 54.26%
// sorted set
// O(NlgN) O(N)
class LUPrefix {
    private SortedSet<Integer> prefixSet = new TreeSet<>();
    private int size = 0;

    public LUPrefix(int n) {
        for (int i = 0; i < n; ++i) {
            prefixSet.add(i);
        }
        size = n;
    }
    
    public void upload(int video) {
        prefixSet.remove(video - 1);
    }
    
    public int longest() {
        if (prefixSet.isEmpty()) {
            return size;
        }
        return prefixSet.first();
    }
}


public class MainApp {
  public static void main(String[] args) {
  }
}
