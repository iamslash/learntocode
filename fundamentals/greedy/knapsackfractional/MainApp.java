// Copyright (C) 2023 by iamslash

import java.util.*;

// items[0]: price
// items[1]: weight

// Idea: greedy
//
// Sort items descending by price / weight.
//   p_b / w_b - p_a / w_a = value 
//   p_b * w_a / w_b - p_a = value * w_a
//   p_b * w_a - p_a * w_b = value * w_a * w_b
// It does not matter value * w_a * w_b.
// We just need value < 0 or value == 0 or value > 0.

// greedy
// O(N) O(1)
class Solution {
    public double maxPrice(int[][] items, int capacity) {
        int n = items.length;
        Arrays.sort(items, (a, b) -> b[0] * a[1] - a[0] * b[1]);
        double priceSum = 0.0, weightSum = 0.0;        
        for (int i = 0; i < n; ++i) {
            double price = (double)items[i][0];
            double weight = (double)items[i][1];
            if (weightSum + weight <= capacity) {
                priceSum += price;
                weightSum += weight;
            } else {
                double diff = capacity - weightSum;
                double ratio = diff / weight;
                priceSum += price * ratio;
                weightSum += diff;
                break;
            }
        }
        // System.out.printf("%f %d\n", weightSum, capacity);
        if (weightSum < capacity) {
            return -1;
        }
        return priceSum;
    }
}
