// Copyright (C) 2025 by iamslash

import java.util.*;


//    k: 3
// nums: 4 -3 2 1 -4 6
//       a  b c
//            3
//              0
//                -1
//                   3

//    k: 2
// nums: -2 -2 3 1 4
//          -4
//             1
//               4
//                 5

// 2 100
//


// Idea: sliding window
//
// The median does not necessarily need to be an element of the given
// array. However, due to the nature of this problem, the optimal
// median will always be one of the elements in the array.
//
// This can be mathematically proven. The value that minimizes the sum
// of absolute differences is always the median of the given
// dataset. More specifically:
//
// If we choose an arbitrary value x to make all array elements equal
// to x, the number of operations required is Sum(|nums[i] - x|).
//
// This function reaches its minimum when x is the median of the
// array.
//
// If x is between two elements of the array (e.g., nums[j] < x <
// nums[j+1]), moving x to either nums[j] or nums[j+1] will result in
// the total number of operations either decreasing or remaining the
// same.
//
// For example, let's assume we have an array [1, 1, 100] and x = 34:
//
// |1 - 34| + |1 - 34| + |100 - 34| = 33 + 33 + 66 = 132
//
// If we change x to 1:
//
// |1 - 1| + |1 - 1| + |100 - 1| = 0 + 1 + 99 = 100

// // Time Limit Exceeded
// // sliding window
// // O(NK^2lgK) O(K)
// class Solution {
//     public long minOperations(int[] nums, int k) {
//         int n = nums.length;
//         long minOps = Long.MAX_VALUE;

//         for (int i = 0; i <= n - k; ++i) {
//             int[] wnd = Arrays.copyOfRange(nums, i, i + k);
//             Arrays.sort(wnd);

//             int median = wnd[k / 2];

//             long ops = 0;
//             for (int j = 0; j < k; ++j) {
//                 ops += Math.abs(wnd[j] - median);
//             }

//             minOps = Math.min(minOps, ops);
//         }

//         return minOps;
//     }
// }


// Time Limit Exceeded
// minheap, maxheap
// O(NlgK) O(N)
class Solution {

    private void rebalance(Queue<Integer> maxHeap, Queue<Integer> minHeap) {
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.offer(maxHeap.poll());
        } else {
            maxHeap.offer(minHeap.poll());
        }
    }
    
    private void addNum(Queue<Integer> maxHeap,
                        Queue<Integer> minHeap,
                        int num) {
        if (maxHeap.isEmpty() || num <= maxHeap.peek()) {
            maxHeap.offer(num);
        } else {
            minHeap.offer(num);
        }

        rebalance(maxHeap, minHeap);
    }

    private void removeNum(Queue<Integer> maxHeap,
                           Queue<Integer> minHeap,
                           int num) {
        if (num <= maxHeap.peek()) {
            maxHeap.remove(num);
        } else {
            minHeap.remove(num);
        }

        rebalance(maxHeap, minHeap);
    }

    private int findMedian(Queue<Integer> maxHeap,
                           Queue<Integer> minHeap) {
        return maxHeap.size() > minHeap.size() ?
            maxHeap.peek() : minHeap.peek();
    }
    
    public long minOperations(int[] nums, int k) {
        int n = nums.length;
        long minOps = Long.MAX_VALUE;

        Queue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        Queue<Integer> minHeap = new PriorityQueue<>();

        for (int i = 0; i < k - 1; ++i) {
            addNum(maxHeap, minHeap, nums[i]);
        }

        for (int i = k - 1; i < n; ++i) {
            addNum(maxHeap, minHeap, nums[i]);

            int median = findMedian(maxHeap, minHeap);

            long ops = 0;
            for (int j = i - k + 1; j <= i; ++j) {
                ops += Math.abs(nums[j] - median);
            }

            minOps = Math.min(minOps, ops);

            removeNum(maxHeap, minHeap, nums[i - k + 1]);
        }

        return minOps;
    }
}




// 553ms 79.17% 71.36MB 20.83%
// double heap
// O(NlgK) O(K)
// ★
class Solution {
    public long minOperations(int[] nums, int k) {
        int n = nums.length;
        
        // Offset all values to avoid negative numbers
        for (int i = 0; i < n; i++) {
            nums[i] += 1000000;
        }
        
        // Special case for k=2
        if (k == 2) {
            long result = Long.MAX_VALUE;
            for (int i = 0; i <= n - k; i++) {
                result = Math.min(result, Math.abs(nums[i] - nums[i + 1]));
            }
            return result;
        }
        
        // Create unique values for TreeSet
        int multiplier = 100000;
        long[] uniqueVals = new long[n];
        for (int i = 0; i < n; i++) {
            uniqueVals[i] = (long)nums[i] * multiplier + i;
        }
        
        TreeSet<Long> window = new TreeSet<>();
        int half = k / 2;
        boolean isOdd = (k & 1) == 1;
        
        // Process first k elements
        Integer[][] firstK = new Integer[k][2];
        for (int i = 0; i < k; i++) {
            firstK[i] = new Integer[]{nums[i], i};
            window.add(uniqueVals[i]);
        }
        Arrays.sort(firstK, (a, b) -> a[0] - b[0]);
        
        // Calculate initial sums and median
        long sumLeft = 0, sumRight = 0;
        long medianVal = firstK[half][0];
        long medianIndex = firstK[half][1];
        long medianUnique = medianVal * multiplier + medianIndex;
        
        for (int i = 0; i < half; i++) {
            sumLeft += firstK[i][0];
        }
        for (int i = half; i < k; i++) {
            sumRight += firstK[i][0];
        }
        
        // Initial result
        long result = medianVal * half - sumLeft + sumRight - medianVal * (k - half);
        
        // Slide window
        for (int i = k; i < n; i++) {
            long addVal = uniqueVals[i], removeVal = uniqueVals[i - k];
            int addNum = nums[i], removeNum = nums[i - k];
            
            // Update sums and median when removing element
            if (isOdd) {
                if (removeVal <= medianUnique) {
                    sumLeft -= removeNum - medianVal;
                    sumRight -= medianVal;
                    medianUnique = window.higher(medianUnique);
                } else {
                    sumRight -= removeNum;
                }
            } else {
                if (removeVal < medianUnique) {
                    sumLeft -= removeNum;
                } else {
                    long lower = window.lower(medianUnique);
                    int lowerNum = (int)(lower / multiplier);
                    sumLeft -= lowerNum;
                    sumRight -= removeNum - lowerNum;
                    medianUnique = lower;
                }
            }
            medianVal = medianUnique / multiplier;
            window.remove(removeVal);
            
            // Update sums and median when adding element
            if (!isOdd) {
                if (addVal < medianUnique) {
                    sumLeft += addNum;
                } else {
                    sumLeft += medianVal;
                    sumRight += addNum - medianVal;
                    long higher = window.higher(medianUnique);
                    medianUnique = (addVal < higher) ? addVal : higher;
                }
            } else {
                if (addVal < medianUnique) {
                    long lower = window.lower(medianUnique);
                    if (addVal < lower) {
                        int lowerNum = (int)(lower / multiplier);
                        sumLeft += addNum - lowerNum;
                        sumRight += lowerNum;
                        medianUnique = lower;
                    } else {
                        sumRight += addNum;
                        medianUnique = addVal;
                    }
                } else {
                    sumRight += addNum;
                }
            }
            medianVal = medianUnique / multiplier;
            window.add(addVal);
            
            // Update result
            long currentResult = medianVal * half - sumLeft + sumRight - medianVal * (k - half);
            result = Math.min(result, currentResult);
        }
        
        return result;
    }
}
