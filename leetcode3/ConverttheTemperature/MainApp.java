// Copyright (C) 2022 by iamslash

import java.util.*;

// math
// O(1) O(1)
// 0ms 100.00% 42.8MB 33.33%
class Solution {
    public double[] convertTemperature(double celsius) {
        return new double[]{celsius + 273.15, celsius * 1.80 + 32.00};
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
