// Copyright (C) 2023 by iamslash

import java.util.*;

// 71ms 29.38% 101.8MB 90.42%
// hash map
// O(1) O(1)
class FrequencyTracker {
    private int[] nums = new int[100_001];
    private int[] freqs = new int[100_001]; 

    public void add(int num) {
        if (nums[num] > 0) {
            freqs[nums[num]]--;
        }
        nums[num]++;
        freqs[nums[num]]++;
    }
    
    public void deleteOne(int num) {
        if (nums[num] == 0) {
            return;
        }
        freqs[nums[num]]--;
        nums[num]--;
        if (nums[num] > 0) {
            freqs[nums[num]]++;
        }
    }
    
    public boolean hasFrequency(int freq) {
        return freqs[freq] > 0;
    }
}
