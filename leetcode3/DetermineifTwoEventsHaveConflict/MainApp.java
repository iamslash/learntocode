// Copyright (C) 2022 by iamslash

import java.util.*;

// 1ms 90.00% 41.6MB 40.00%
// geometry
// O(1) O(1)
class Solution {
    public boolean haveConflict(String[] evt1, String[] evt2) {
        return evt1[0].compareTo(evt2[1]) <= 0 &&
            evt2[0].compareTo(evt1[1]) <= 0;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
