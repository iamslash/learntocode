// Copyright (C) 2022 by iamslash

import java.util.*;

// i
// 2 2 3 3
//       j
//

// 
// 1 10 1
// 10
// 11

// 4ms 85.29% 57.3MB 78.05%
// two pointers
// O(N) O(1)
class Solution {
    public int minimumRefill(int[] plants, int capacityA, int capacityB) {
        int n = plants.length, refill = 0;
        int idxA = 0, idxB = n-1, canA = capacityA, canB = capacityB; 
        while (idxA <= idxB) {
            if (idxA == idxB) {
                if (plants[idxA] > Math.max(canA, canB)) {
                    refill++;
                }
                // System.out.printf("canA: %d, canB: %d, plants[idxA]: %d\n", canA, canB, plants[idxA]);
                break;
            }
            // Alice
            if (canA < plants[idxA]) {
                canA = capacityA;
                refill++;
            }
            canA -= plants[idxA];
            idxA += 1;
            // Bob
            if (canB < plants[idxB]) {
                canB = capacityB;
                refill++;
            }
            canB -= plants[idxB];
            idxB -= 1;
        }
        return refill;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
