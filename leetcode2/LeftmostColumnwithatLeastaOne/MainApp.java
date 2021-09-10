// Copyright (C) 2021 by iamslash

import java.util.*;

// x
// 0 0 0 1 
// 0 0 1 1 
// 0 1 1 1 y

// 1ms 20.38% 44.5MB 22.38%
// linear traversal
// O(HW) O(1)
class Solution {
    public int leftMostColumnWithOne(BinaryMatrix binaryMatrix) {
        int h = binaryMatrix.dimensions().get(0);
        int w = binaryMatrix.dimensions().get(1);
        int y = 0, x = w-1, col = -1;
        while (y < h && x >= 0) {
            if (binaryMatrix.get(y, x) == 0) {
                ++y;
            } else {
                col = x--;
            }
        }
        return col;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
