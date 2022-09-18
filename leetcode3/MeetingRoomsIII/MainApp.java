// Copyright (C) 2022 by iamslash

import java.util.*;

// Wrong Answer
// heap
// O(MlgN) O(N)
// M: count of meetings
// N: count of rooms
class Solution {
    public int mostBooked(int n, int[][] meetings) {
        Arrays.sort(meetings, (a, b) -> a[0] - b[0]);
        // [availStartTime, roomNo]
        Queue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        for (int i = 0; i < n; ++i) {
            pq.offer(new int[]{0, i});
        }
        // {roomNo: meeting cnt}
        int[] room2Cnts = new int[n];
        for (int[] meeting: meetings) {
            int meetingStartTime = meeting[0];
            // rebalance
            while (pq.peek()[0] < meetingStartTime) {
                pq.add(new int[]{meetingStartTime, pq.poll()[1]});
            }
            int[] availItem = pq.poll();
            int availRoomNo = availItem[1];
            int availStartTime = availItem[0] + (meeting[1] - meeting[0]);
            room2Cnts[availRoomNo]++;
            pq.add(new int[]{availStartTime, availRoomNo});
        }
        int maxRoomNo = 0;
        for (int i = 1; i < n; i++) {
            if (room2Cnts[i] > room2Cnts[maxRoomNo])
                maxRoomNo = i;
        }
        return maxRoomNo;
    }
}

// 178ms 43.68% 145.5MB 23.75%
// heap
// O(MlgN) O(N)
// M: count of meetings
// N: count of rooms
class Solution {
    public int mostBooked(int n, int[][] meetings) {
        Arrays.sort(meetings, (a, b) -> a[0] - b[0]);
        int[] room2Cnts = new int[n];
        // [engaged room no, engaed end time]
        Queue<int[]> engagedPq = new PriorityQueue<>((a, b) -> a[1] == b[1] ? a[0] - b[0] : a[1] - b[1]);
        // avail room no
        Queue<Integer> unusedPq = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            unusedPq.offer(i);
        }
        for (int[] meeting: meetings) {
            int start = meeting[0], end = meeting[1];
            while (!engagedPq.isEmpty() && engagedPq.peek()[1] <= start) {
                int room = engagedPq.poll()[0];
                unusedPq.offer(room);
            }
            if (unusedPq.size() > 0) {
                int room = unusedPq.poll();
                room2Cnts[room]++;
                engagedPq.offer(new int[] {room, end});
            } else {
                int[] cur = engagedPq.poll();
                int room = cur[0], curEnd = cur[1];
                room2Cnts[room]++;
                int newEnd = curEnd + end - start;
                engagedPq.offer(new int[] {room, newEnd});
            }
        }
        int maxRoomNo = 0;
        for (int i = 1; i < n; i++) {
            if (room2Cnts[i] > room2Cnts[maxRoomNo])
                maxRoomNo = i;
        }
        return maxRoomNo;
    }
}
