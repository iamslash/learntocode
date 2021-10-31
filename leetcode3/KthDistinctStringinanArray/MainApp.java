// Copyright (C) 2021 by iamslash

import java.util.*;

//     arr: d b c b c a
// freqMap: a b c d
//          1 2 2 1

// 5ms 60.00% 38.7MB 60.00%
// hash map
// O(N) O(N)
class Solution {
    public String kthDistinct(String[] arr, int k) {
        Map<String, Integer> freqMap = new HashMap<>();
        for (String s : arr) {
            freqMap.putIfAbsent(s, 0);
            freqMap.put(s, freqMap.get(s) + 1);
        }
        for (String s : arr) {        
            Integer cnt = freqMap.get(s);
            if (cnt != null && cnt == 1) {
                if (--k == 0) {
                    return s;
                }
            }
        }
        return "";
    }
}

// 3ms 80.00% 38.7MB 60.00%
// hash set
// O(N) O(N)
class Solution {
    public String kthDistinct(String[] arr, int k) {
        Set<String> once = new HashSet<>();
        Set<String> more = new HashSet<>();
        for (String s : arr) {
            if (more.contains(s)) {
                continue;
            }
            if (once.contains(s)) {
                more.add(s);
                once.remove(s);
                continue;
            }
            once.add(s);
        }
        for (String s : arr) {
            if (once.contains(s)) {
                --k;
            }
            if (k == 0) {
                return s;
            }
        }
        return "";
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
