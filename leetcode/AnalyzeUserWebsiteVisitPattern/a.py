# -*- coding: utf-8 -*-
# Copyright (C) 2022 by iamslash

# 90ms 15.40% 14.7MB 58.53
# hash map
class Solution:
    def mostVisitedPattern(self, username: List[str], timestamp: List[int], website: List[str]) -> List[str]:
        C = collections.defaultdict(list);
        for t, u, w in sorted(zip(timestamp, username, website)):
            C[u].append(w);
        webCounter = Counter()
        for u, w in C.items():
            webCounter.update(Counter(set(combinations(w, 3))))
        return max(sorted(webCounter), key=webCounter.get)
