// Copyright (C) 2021 by iamslash

import java.util.*;

/**
 * // This is the GridMaster's API interface.
 * // You should not implement it, or speculate about its implementation
 * class GridMaster {
 *     boolean canMove(char direction);
 *     int move(char direction);
 *     boolean isTarget();
 * }
 */

// 61ms 37.14% 41.8MB 61.43%
// backtracking, dijkstra
// O(N) O(N)
class Solution {
	private final char[] DIR = {'U', 'R', 'D', 'L'};
	private final int[][] STEP = {{-1,0},{0,1},{1,0},{0,-1}};
	Map<Pair<Integer, Integer>, Integer> G = new HashMap();
	Pair<Integer, Integer> dst = null;
	private void dfs(GridMaster master, int y, int x) {
		// base
		if (master.isTarget()) {
			dst = new Pair(y, x);
		}
		// recursion
		for (int i = 0; i < 4; ++i) {
			int ny = y + STEP[i][0];
			int nx = x + STEP[i][1];
			int v  = new Pair(ny, nx);
			if (G.containsKey(v) || !master.canMove(DIR[i])) {
				continue;
			}
			int nc = master.move(DIR[i]);
			G.put(new Pair(ny, nx), nc);
			dfs(master, ny, nx);
			// return to back
			master.move(DIR[(i+2) % 4]);
		}
	}
	public int findShortestPath(GridMaster master) {
		dfs(master, 0, 0);
		if (dst == null) {
			return -1;
		}
		PriorityQueue<int[]> pq = new PriorityQueue<int[]>((a, b)-> a[0] - b[0]);
		pq.offer(new int[]{0, 0, 0});
		// loop
		while (!pq.isEmpty()) {
			int[] u = pq.poll();
			if (u[1] == dst.getKey() && u[2] == dst.getValue()) {
				return u[0];
			}
			// traverse
			for (int i = 0; i < 4; ++i) {
				int ny = u[1] + STEP[i][0];
				int nx = u[2] + STEP[i][1];
				Pair<Integer, Integer> v = new Pair{ny, nx};
				if (!G.containsKey(v)) {
					continue;
				}
				int nc = G.remove(v) + u[0];
				pq.offer(new int[]{nc, ny, nx});
			}
		}
		return -1;
	}
}

// 23ms 100.00% 41.4MB 78.57%
// dfs, dijkstra
// O(ElgV) O(V)
class Solution {
	int size = 101;
	// robot start from center
	Integer[][] G = new Integer[size*2][size*2];
	GridMaster master;
	final char[] DIR = new char[]{'U', 'L', 'D', 'R'};
	final int[][] STEP = {{-1,0},{0,1},{1,0},{0,-1}};
	int min = Integer.MAX_VALUE;
	int[] dst = null;
	void dfs(int y, int x) {
		// base
		if (master.isTarget()) {
			dst = new int[]{y, x};
		}
		// recursion
		for (int i = 0; i < 4; ++i) {
			if (!master.canMove(DIR[i])) {
				continue;
			}
			int ny = y + STEP[i][0];
			int nx = x + STEP[i][1];
			if (G[ny][nx] != null) {
				continue;
			}
			G[ny][nx] = master.move(DIR[i]);
			dfs(ny, nx);
			master.move(DIR[(i+2) % 4]);
		}
	}
	public int findShortestPath(GridMaster master) {
		this.master = master;
		dfs(size, size);
		if (dst == null) {
			return -1;
		}
		PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0]-b[0]);
		pq.offer(new int[]{0, size, size});
		while (!pq.isEmpty()) {
			int[] u = pq.poll();
			if (u[1] == dst[0] && u[2] == dst[1]) {
				return u[0];
			}
			for (int i = 0; i < 4; ++i) {
				int ny = u[1] + STEP[i][0];
				int nx = u[2] + STEP[i][1];
				if (G[ny][nx] == null) {
					continue;
				}
				int nc = u[0] + G[ny][nx];
				G[ny][nx] = null;
				pq.offer(new int[]{nc, ny, nx});
			}
		}
		return -1;
	}	
}

public class MainApp {
  public static void main(String[] args) {
  }
}
