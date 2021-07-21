// Copyright (C) 2021 by iamslash

import java.util.*;

// 3ms 100.00% 40.2MB 83.14%
// BFS
// O(HW) O(HW)
class Solution {
	public int nearestExit(char[][] maze, int[] ent) {
		int h = maze.length, w = maze[0].length;
		int[] dirs = new int[]{-1, 0, 1, 0, -1};
		Queue<int[]> q = new LinkedList<>();
		q.offer(new int[]{ent[0], ent[1], 0});
		while (q.size() > 0) {
			int[] item = q.poll();
			int y = item[0];
			int x = item[1];
			int step = item[2];
			// System.out.printf("y:%d, x:%d, h:%d, w:%d, ent[0]:%d, ent[1]:%d\n", y, x, h, w, ent[0], ent[1]);            
			if ((y != ent[0] || x != ent[1]) && 
					(y == 0 || y == h-1 || x == 0 || x == w-1)) {
				return step;
			}
			for (int i = 0; i < 4; ++i) {
				int ny = y + dirs[i];
				int nx = x + dirs[i+1];
				// System.out.printf("ny:%d, nx:%d, h:%d, w:%d\n", ny, nx, h, w);
				if (ny >= 0 && ny < h && nx >= 0 && nx < w && maze[ny][nx] == '.') {
					maze[ny][nx] = '+';
					q.offer(new int[]{ny, nx, step+1});
				}
			}
		}
		return -1;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
