// Copyright (C) 2021 by iamslash

import java.util.*;

//    seats: 1 3 5
// students: 2 4 7

//    seats: 1 4 5 9
// students: 1 2 3 6

//    seats: 2 2 6 6
// students: 1 2 3 6

// 1ms 100.00% 38.5MB 66.67%
// sort
// O(NlgN) O(1)
class Solution {
    public int minMovesToSeat(int[] seats, int[] students) {
        Arrays.sort(seats);
        Arrays.sort(students);
        int diff = 0;
        for (int i = 0; i < seats.length; ++i) {
            diff += Math.abs(seats[i] - students[i]);
        }
        return diff;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
