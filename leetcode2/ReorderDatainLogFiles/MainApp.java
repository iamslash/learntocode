// Copyright (C) 2021 by iamslash

import java.util.*;

// 5ms 76.13% 39.5MB 68.95%
// sort
// O(NlgN) O(1)
class Solution {
    public String[] reorderLogFiles(String[] logs) {
        Comparator<String> cmp = (String a, String b) -> {
            String[] aa = a.split(" ", 2);
            String[] bb = b.split(" ", 2);
            boolean aLetter = Character.isLetter(aa[1].charAt(0));
            boolean bLetter = Character.isLetter(bb[1].charAt(0));
            if (aLetter && bLetter) {
                int ord = aa[1].compareTo(bb[1]);
                if (ord == 0) {
                    return aa[0].compareTo(bb[0]);
                }
                return ord;
            } else if (aLetter && !bLetter) {
                return -1;
            } else if (!aLetter && bLetter) {
                return 1;
            }
            return 0;
        };
        Arrays.sort(logs, cmp);
        return logs;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
