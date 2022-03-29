// Copyright (C) 2022 by iamslash

import java.util.*;

//        i
// street: .H.HH.
//         j
// street: .**H.
//         ...


// count of buckets: all_buckets - adj_buckets
//                   (n - adj_buckets) - (n - all_buckets)
//                   s.replace("H.H", "**").length() - s.replace("H", "").length()
// 15ms 34.94% 52.2MB 20.88%
// greedy
// O(N) O(1)
class Solution {
    public int minimumBuckets(String street) {
        if (street.equals("H") ||
            street.startsWith("HH") ||
            street.endsWith("HH") ||
            street.contains("HHH")) {
            return -1;
        }
        return street.replace("H.H", "  ").length() -
            street.replace("H", "").length();
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
