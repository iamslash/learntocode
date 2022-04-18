// Copyright (C) 2022 by iamslash

import java.util.*;

// 24ms 83.04% 54.6MB 96.21%
// sort
// O(NlgN) O(N)
class Solution {
    public boolean asteroidsDestroyed(int mass, int[] asteroids) {
        long planet = mass;
        Arrays.sort(asteroids);
        for (int ast : asteroids) {
            if (planet < ast) {
                return false;
            }
            planet += ast;
        }
        return true;
    }
}

class Solution {
    public boolean asteroidsDestroyed(int mass, int[] asteroids) {
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
