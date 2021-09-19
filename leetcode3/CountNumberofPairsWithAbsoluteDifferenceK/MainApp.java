// Copyright (C) 2021 by iamslash

// 1ms 77.78% 38.4MB 33.33%
// hash map
// O(N) O(N)
class Solution {
    public int countKDifference(int[] nums, int k) {
        int cnt = 0;
        int[] freqs = new int[101];        
        for (int num : nums) {
            freqs[num]++;
        }
        for (int num : nums) {
            if (num - k > 0) {
                cnt += freqs[num-k];
            }
            if (num + k <= 100) {
                cnt += freqs[num+k];    
            }
        }
        return cnt/2;
    }
}

// 1ms 77.78% 38.3MB 44.44%
// hash map
// O(N) O(N)
class Solution {
    public int countKDifference(int[] nums, int k) {
        int cnt = 0;
        int[] freqs = new int[101];        
        for (int num : nums) {
            freqs[num]++;
        }
        for (int num = 1; num <= 100; ++num) {
            if (num + k <= 100) {
                cnt += freqs[num] * freqs[num+k];
            }
            if (num - k > 0) {
                cnt += freqs[num] * freqs[num-k];
            }
        }
        return cnt/2;
    }    
}

public class MainApp {
  public static void main(String[] args) {
  }
}
