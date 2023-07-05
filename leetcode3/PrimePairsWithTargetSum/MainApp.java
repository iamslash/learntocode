// Copyright (C) 2023 by iamslash

import java.util.*;

//               i
// primes: 0 1 2 3 4 5 6 7 8
//         f f t t f   f   f
//               j

// 181ms 92.62% 52.1MB 82.68%
// sieve of eratosthenes
// O(Nsqrt(N)) O(N)
class Solution {
    public List<List<Integer>> findPrimePairs(int n) {
        boolean[] primes = new boolean[n + 1];
        Arrays.fill(primes, true);
        primes[0] = primes[1] = false;
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 2; i * i <= n; i++) {
            if (primes[i] == false) {
                continue;
            }
            for (int j = i * i; j <= n; j += i) {
                primes[j] = false;
            }
        }
        for (int x = 2; x <= n / 2; ++x) {
            if (primes[x] && primes[n - x]) {
                ans.add(Arrays.asList(x, n - x));
            }
        }
        return ans;
    }
}
