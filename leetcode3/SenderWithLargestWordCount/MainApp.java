// Copyright (C) 2022 by iamslash

import java.util.*;

// 133ms 45.70% 104.9MB 68.57%
// hash map
// O(N) O(N)
class Solution {
    public String largestWordCount(String[] msgs, String[] senders) {
        Map<String, Integer> cntMap = new HashMap<>();
        int n = msgs.length, maxCnt = 0;
        String maxSender = "";
        for (int i = 0; i < n; ++i) {
            String sender = senders[i];
            int cnt = msgs[i].split(" ").length;
            cntMap.put(sender, cntMap.getOrDefault(sender, 0) + cnt);
        }
        for (String sender : cntMap.keySet()) {
            int cnt = cntMap.get(sender);
             if (maxSender.isEmpty() ||
                maxCnt < cnt ||
                (maxCnt == cnt && maxSender.compareTo(sender) < 0)) {
                maxSender = sender;
                maxCnt = cnt;
            }
        }
        // System.out.println(cntMap);
        return maxSender;
    }
}
