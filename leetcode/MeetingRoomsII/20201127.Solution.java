// Copyright (C) 2020 by iamslash

// class Solution {
//   public int minMeetingRooms(int[][] I) {
//     Map<Integer, Integer> eventMap = new TreeMap<>();
//     for (int[] interval : I) {
//       eventMap.put(interval[0], eventMap.getOrDefault(interval[0], 0) + 1);
//       eventMap.put(interval[1], eventMap.getOrDefault(interval[1], 0) - 1);
//     }
//     int ans = 0, cur = 0;
//     for (int val : eventMap.values()) {
//       ans = Math.max(ans, cur += val);
//     }
//     return ans;
//   }
// }

// 1ms 100.00% 39.2MB 85.97%
class Solution {
  public int minMeetingRooms(int[][] I) {
    if (I == null || I.length == 0 || I[0].length == 0)
      return 0;
    int n = I.length;
    int[] begArr = new int[n];
    int[] endArr = new int[n];
    for (int i = 0; i < n; ++i) {
      begArr[i] = I[i][0];
      endArr[i] = I[i][1];
    }
    Arrays.sort(begArr);
    Arrays.sort(endArr);
    int j = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (begArr[i] < endArr[j]) {
        ans++;
      } else {
        j++;
      }
    }
    return ans;
  }
}
