// Copyright (C) 2025 by iamslash

import java.util.*;

//     days: 10
// meetings: 5,7 1,3 9,10
//           . . . . . . . . . .
//           -----
//                   -----
//                           ---
//


// 42ms 34.77% 96.36MB 95.03%
// sort
// O(NlgN) O(N)
class Solution {
    public int countDays(int days, int[][] meetings) {
        Arrays.sort(meetings, (a, b) -> a[0] - b[0]);

        List<int[]> mergedList = new ArrayList<>();
        for (int[] meeting : meetings) {
            if (mergedList.size() == 0 ||
                mergedList.get(mergedList.size() - 1)[1] < meeting[0]) {
                mergedList.add(meeting);
            } else {
                int[] last = mergedList.get(mergedList.size() - 1);
                last[1] = Math.max(last[1], meeting[1]);
            }
        }

        System.out.println(mergedList);
        
        int meetingDays = 0;
        for (int[] meeting : mergedList) {
            meetingDays += (meeting[1] - meeting[0] + 1);
        }

        return days - meetingDays;
    }
}
