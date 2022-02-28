// Copyright (C) 2022 by iamslash

import java.util.*;

// Idea:
// In case of 28
// These are same answers.
//           2 4 6 16
//           2 6 8 12
// Just increase num by 2 from 2 to get many splits.

// 32ms 26.43% 119.2MB 51.98%
// greedy
// O(N) O(N)
class Solution {
    public List<Long> maximumEvenSplit(long finalSum) {
        List<Long> ans = new ArrayList<>();
        if (finalSum % 2 != 0) {
            return ans;
        }
        long prev = 2;
        while (prev < (finalSum / 2)) {
            if ((finalSum - prev) % 2 == 0) {
                ans.add(prev);
                finalSum -= prev;
            }
            prev += 2;
        }
        ans.add(finalSum);
        return ans;
    }
}

// 25ms 41.13% 120.4MB 45.77%
// greedy
// O(N) O(N)
class Solution {
    public List<Long> maximumEvenSplit(long finalSum) {
        List<Long> ans = new ArrayList<>();
        if (finalSum % 2 != 0) {
            return ans;
        }
        long num = 2;
        while (num * 2 < finalSum) {
            ans.add(num);
            finalSum -= num;
            num += 2;
        }
        ans.add(finalSum);
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
