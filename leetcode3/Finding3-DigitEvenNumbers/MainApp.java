// Copyright (C) 2021 by iamslash

import java.util.*;

// 5ms 89.22% 39.2MB 91.37%
// brute force
// O(N^3) O(N^3)
class Solution {
    private void dump(int[] A) {
        for (int a : A) {
            System.out.printf("%d ", a);
        }
        System.out.println();
    }
    public int[] findEvenNumbers(int[] digits) {
        List<Integer> ans = new ArrayList<>();
        int[] freqs = new int[10];
        for (int digit : digits) {
            freqs[digit]++;
        }
        // dump(freqs);
        for (int i = 1; i < 10; ++i) {
            for (int j = 0; freqs[i] > 0 && j < 10; ++j) {
                if (freqs[j] == 0 || (i == j && freqs[j] < 2)) {
                    continue;
                }
                for (int k = 0; k < 10; k += 2) {
                    if (freqs[k] == 0) {
                        continue;
                    }
                    int same = (i == k) ? 1 : 0;
                    same += (j == k) ? 1 : 0;
                    // System.out.printf("i:%d, j:%d, k: %d, same:%d\n", i, j, k, same);                    
                    if (freqs[k] <= same) {
                        continue;
                    }

                    ans.add(i * 100 + j * 10 + k);
                }
            }
        }
        return ans.stream()
            .mapToInt(Integer::intValue)
            .toArray();
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
