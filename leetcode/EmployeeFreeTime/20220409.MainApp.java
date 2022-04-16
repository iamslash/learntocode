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

// 1,2 5,6
// 1,3 4,10

// 1 2     5 6
// 1   3 4     10

// 13ms 73.59% 55.5MB 14.28%
// sort
// O(NlgN) O(N)
class Solution {
    public List<Interval> employeeFreeTime(List<List<Interval>> schedule) {
        List<Interval> ans = new ArrayList<>();
        List<Interval> intervalList = new ArrayList<>();
        for (List<Interval> scheduleList : schedule) {
            intervalList.addAll(scheduleList);
        }
        intervalList.sort((a, b) -> {
                if (a.start == b.start) {
                    return a.end - b.end;
                }
                return a.start - b.start;
            });
        Interval prvEvt = intervalList.get(0);
        for (Interval curEvt : intervalList) {
            if (curEvt.start <= prvEvt.end) {
                prvEvt.end = Math.max(prvEvt.end, curEvt.end);
            } else {
                ans.add(new Interval(prvEvt.end, curEvt.start));
                prvEvt = curEvt;
            }
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
