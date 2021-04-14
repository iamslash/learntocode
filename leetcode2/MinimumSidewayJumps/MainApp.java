// Copyright (C) 2021 by iamslash

import java.util.*;

// . x . . .
// f . x . .
// . . . x .

class Solution {
	public int minSideJumps(int[] obstacles) {
		// lane, point, side jumps
		Queue<int[]> q = new ArrayDeque<>();
		q.offer(new int[]{0,2,0});
		while (q.size() > 0) {
			int[] item = q.poll();
			if (item[0] >= obstacles.length) {
				return item[2];
			}
		}
		return 0;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
