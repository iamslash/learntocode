// Copyright (C) 2021 by iamslash

import java.util.*;

//  dist: 1 3 4
// speed: 1 1 1
//        i
//  dist: 0 2 3
// 

// 15ms 97.88% 48.4MB 93.08%
// sort
// O(N) O(1)
class Solution {
	public int eliminateMaximum(int[] dist, int[] speed) {
		// save duration
		for (int i = 0; i < dist.length; ++i) {
			dist[i] = (dist[i] - 1) / speed[i];
		}
		Arrays.sort(dist);
		for (int i = 0; i < dist.length; ++i) {
			if (i > dist[i]) {
				return i;
			}
		}
		return dist.length;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
