// Copyright (C) 2025 by iamslash

import java.util.*;

// 9ms 68.21% 47.38MB 45.17%
// iterative dynamic programming
// O(N) O(N)
class Solution {
    public double maxAmount(String initialCurrency, List<List<String>> pairs1, double[] rates1, List<List<String>> pairs2, double[] rates2) {
        // {currency : The biggest currency}
        Map<String, Double> cache = new HashMap<>();
        cache.put(initialCurrency, 1.0);

        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < pairs1.size(); ++j) {
                String a = pairs1.get(j).get(0), b = pairs1.get(j).get(1);
                cache.put(b,
                          Math.max(cache.getOrDefault(b, 0.0),
                                   cache.getOrDefault(a, 0.0) * rates1[j]));
                cache.put(a,
                          Math.max(cache.getOrDefault(a, 0.0),
                                   cache.getOrDefault(b, 0.0) / rates1[j]));
            }
        }

        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < pairs2.size(); ++j) {
                String a = pairs2.get(j).get(0), b = pairs2.get(j).get(1);
                cache.put(b,
                          Math.max(cache.getOrDefault(b, 0.0),
                                   cache.getOrDefault(a, 0.0) * rates2[j]));
                cache.put(a,
                          Math.max(cache.getOrDefault(a, 0.0),
                                   cache.getOrDefault(b, 0.0) / rates2[j]));
            }
        }

        return cache.get(initialCurrency);              
    }
}
