// Copyright (C) 2023 by iamslash

import java.util.*;

// a: 0532
// a: 0549
// a: 0621
// b: 0457
// b: 0540

// 8ms 99.07% 44.7MB 57.20%
// sort
// O(NlgN) O(N)
class Solution {
    public List<String> findHighAccessEmployees(List<List<String>> accessTimes) {
        int n = accessTimes.size();
        Map<String, List<Integer>> user2timesMap = new HashMap<>();
        for (List<String> accTime : accessTimes) {
            String user = accTime.get(0);
            int time = Integer.valueOf(accTime.get(1));
            user2timesMap.putIfAbsent(user, new ArrayList<>());
            user2timesMap.get(user).add(time);
        }
        List<String> ans = new ArrayList<>();
        for (String user : user2timesMap.keySet()) {
            List<Integer> timeList = user2timesMap.get(user);
            if (timeList.size() < 3) {
                continue;
            }
            Collections.sort(timeList);
            int len = timeList.size();
            for (int i = 0; i < len - 2; ++i) {
                if (timeList.get(i) + 100 > timeList.get(i+2)) {
                    ans.add(user);
                    break;
                }
            }
        }
        return ans;
    }
}
