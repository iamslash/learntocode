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
