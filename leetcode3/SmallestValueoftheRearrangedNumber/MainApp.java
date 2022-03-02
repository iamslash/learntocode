// Copyright (C) 2022 by iamslash

import java.util.*;

// num: 310
//      013
//
// num: -310
//       310

// 4ms 62.05% 41.8MB 19.42%
// sort
// O(NlgN) O(N)
class Solution {
    public long smallestNumber(long num) {
        if (num == 0) {
            return 0;
        }
        boolean neg = false;
        if (num < 0) {
            neg = true;
            num = -num;
        }
        List<Integer> digitList = new ArrayList<>();
        while (num > 0) {
            digitList.add((int)(num % 10L));
            num /= 10L;
        }       
        // System.out.println(digitList);
        if (neg) {
            Collections.sort(digitList, Collections.reverseOrder());
        } else {
            Collections.sort(digitList);
            if (digitList.get(0) == 0) {
                int i = 0;
                for (i = 1; i < digitList.size(); ++i) {
                    if (digitList.get(i) > 0) {
                        break;
                    }
                }
                // switch value of 0, i idx
                digitList.set(0, digitList.get(i));
                digitList.set(i, 0);
            }
        }
        long ans = 0;
        for (int i = 0; i < digitList.size(); ++i) {
            ans = ans * 10L + digitList.get(i);
        }
        if (neg) {
            ans = -ans;
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
