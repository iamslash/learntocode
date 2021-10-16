// Copyright (C) 2021 by iamslash

import java.util.*;

//      i
//      5
// 4
//    3
//  2  2
//
//   0
//      j
//   leftHeight: 4 
//  rightHeight: 0
//   leftWater: 9
//  rightWater: 0
//       water: 

//     i
//   1
//  0 0
//    j

//        i          
//        3
//    2    2 2 
//  1  1 1  1 1
// 0 0  0 
//        j
//   leftHeight: 3
//  rightHeight: 2
//   leftWater: 4
//  rightWater: 0
//       water: 2

// 1ms 90.67% 38.6MB 68.70%
// two pointers
// O(N) O(1)
class Solution {
    public int trap(int[] H) {
        int n = H.length, i = 0, j = n-1, trapWater = 0;
        int leftHeight = 0, rightHeight = 0, leftWater = 0, rightWater = 0;
        while (i < j) {
            if (H[i] <= H[j]) {
                if (H[i] >= leftHeight) {
                    trapWater += leftWater;
                    leftWater = 0;
                } 
                leftHeight = Math.max(leftHeight, H[i]);
                leftWater += leftHeight - H[i];
                ++i;
            } else {
                if (H[j] >= rightHeight) {
                    trapWater += rightWater;
                    rightWater = 0;
                }
                rightHeight = Math.max(rightHeight, H[j]);
                rightWater += rightHeight - H[j];
                --j;
            }
        }
        return trapWater + leftWater + rightWater;
    }
}

// 0ms 100.00% 38.4MB 87.22%
// two pointers
// O(N) O(1)
class Solution {
    public int trap(int[] H) {
        int i = 0, j = n-1, trapWater = 0;
        int leftMaxH = H[i], rightMaxH = H[j];
        while (i < j) {
            if (leftMaxH < rightMaxH) {
                i++;
                leftMaxH = Math.max(leftMaxH, H[i]);
                trapWater += leftMaxH - H[i];
            } else {
                j--;
                rightMaxH = Math.max(rightMaxH, H[j]);
                trapWater += rightMaxH - H[j];
            }
        }
        return trapWater;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
