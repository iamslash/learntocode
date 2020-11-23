// Copyright (C) 2020 by iamslash

import java.util.*;

//    target: 100
// startFuel: 10
//                                      i
//  stations: 10,60 20,30 30,30 60,40
//   maxDist:    10    70             110
//         q: 30 30   
//       ans:     0     2

// 4ms 55.24% 39.4MB 83.74%
// greedy algorithm
// O(NlgN) O(N)
class Solution {
	public int minRefuelStops(int target, int startFuel, int[][] stations) {
		if (startFuel > target)
			return 0;
		Queue<Integer> q = new PriorityQueue<Integer>((a, b) -> b - a);
		int i = 0, ans = 0, maxDist = startFuel, n = stations.length;
		while (maxDist < target) {
			while (i < n && stations[i][0] <= maxDist) {
				q.offer(stations[i][1]);
				i++;
			}
			if (q.isEmpty())
				return -1;
			maxDist += q.poll();
			ans++;
		}
		return ans;		
	}
}
