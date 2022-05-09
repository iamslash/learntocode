// Copyright (C) 2022 by iamslash

import java.util.*;

//   i
// 1 2 4
// 4 3 6
// j

//       i
//   1 2 3
//   5 6 10
//   j

// Wrong Answer:
// [[33889,98676],
//  [80071,89737],
//  [44118,52565],
//  [52992,84310],
//  [78492,88209],
//  [21695,67063],
//  [84622,95452],
//  [98048,98856],
//  [98411,99433],
//  [55333,56548],
//  [65375,88566],
//  [55011,62821],
//  [48548,48656],
//  [87396,94825],
//  [55273,81868],
//  [75629,91467]]
// 6
// Reason: Need to save returned seat number
//
// two pointers, sort
// O(NlgN) O(1)
class Solution {
    public int smallestChair(int[][] times, int targetFriend) {
        int tgtBeg = times[targetFriend][0], n = times.length;
        Arrays.sort(times, (a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        for (int i = 0, j = 0; i < n; ++i) {
            while (times[j][1] <= times[i][0]) {
                j++;
            }
            if (times[i][0] == tgtBeg) {
                return i - j;
            }
        }
        return -1;
    }
}

//             i
// 1 2 3 4 5 6 7
// 5 5 5 5 6 9 9
//           j

// 54ms 80.27% 49.5MB 92.52%
// heap
// O(NlgN) O(N)
class Solution {
    public int smallestChair(int[][] times, int targetFriend) {
        int tgtBeg = times[targetFriend][0], n = times.length;
        Arrays.sort(times, (a, b) -> a[0] - b[0]);        
        Queue<Integer> availSeatPq = new PriorityQueue<>();
        for (int i = 0; i < n; ++i) {
            availSeatPq.offer(i);
        }
        // [leave time, avail seat]
        Queue<int[]> leaveTimePq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        for (int i = 0; i < n; ++i) {
            while (!leaveTimePq.isEmpty() && leaveTimePq.peek()[0] <= times[i][0]) {
                availSeatPq.offer(leaveTimePq.poll()[1]);
            }
            if (times[i][0] == tgtBeg) {
                break;
            }
            leaveTimePq.offer(new int[]{times[i][1], availSeatPq.poll()});
        }
        return availSeatPq.peek();
    }
}
