// Copyright (C) 2024 by iamslash

import java.util.*;

// 4ms 29.04% 61.5MB 44.96%
// kadane algorithm
// O(N) O(N)
class Solution {
    public int maximumEnergy(int[] energy, int k) {
        int n = energy.length, maxEnergy = -1_000;
        int[] C = new int[k];
        Arrays.fill(C, -1_000);

        for (int i = 0; i < n; ++i) {
            C[i % k] = Math.max(energy[i], energy[i] + C[i % k]);
        }

        for (int i = 0; i < C.length; ++i) {
            maxEnergy = Math.max(maxEnergy, C[i]);
        }

        return maxEnergy;
    }
}

//      k: 3
// energy: 5 2 -10 -5 1
//                  i

// 2ms 97.83% 59.9MB 72.69%
// O(N) O(1)
class Solution {
    public int maximumEnergy(int[] energy, int k) {
        int maxE = Integer.MIN_VALUE, n = energy.length;

        for (int i = n - 1; i >= n - k; --i) {

            int curE = 0;
            for (int j = i; j >= 0; j = j - k) {
                curE = curE + energy[j];
                maxE = Math.max(maxE, curE);
            }
        }

        return maxE;
    }
}
