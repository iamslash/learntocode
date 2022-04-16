// Copyright (C) 2022 by iamslash

import java.util.*;

class Interval {
    public int start;
    public int end;
    public Interval() {}
    public Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};

// [1,2],[5,6] [1,3] [4,10]
//
//       4           10
// 1   3
// 1 2     5 6

// [1,3],[6,7] [2,4],[2,5],[9,12]
// 1   3     6 7
//   2   4
//   2     5       9 12

// 9ms 92.67% 55.3MB 24.50%
// sort
// O(N) O(N)
class Solution {
    public List<Interval> employeeFreeTime(List<List<Interval>> schedule) {
        List<Interval> ans = new ArrayList<>();
        List<Interval> evtList = new ArrayList<>();
        for (List<Interval> l : schedule) {
            evtList.addAll(l);
        }
        evtList.sort((a, b) -> {
                if (a.start == b.start) {
                    return a.end - b.end;
                }
                return a.start - b.start;
            });
        int prvEnd = -1;
        for (Interval evt : evtList) {
            if (prvEnd > 0 && prvEnd < evt.start) {
                ans.add(new Interval(prvEnd, evt.start));
            }
            prvEnd = Math.max(prvEnd, evt.end);
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
