// Copyright (C) 2021 by iamslash

// dfs
// O(HW) O(HW)
class Solution {
	private Set<String> visit = new HashSet<>();
	private void back(Robot robot) {
		robot.turnRight();
		robot.turnRight();
		robot.move();
		robot.turnRight();
		robot.turnRight();
	}
	private void dfs(Robot robot, int y, int x, int dir) {
		// base
		visit.add(String.format("%d.%d", y, x));
		robot.clean();
		int dy[] = new int[]{-1, 0, 1,  0};
		int dx[] = new int[]{ 0, 1, 0, -1};
		// recursion
		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			String pos = String.format("%d.%d", ny, nx);
			if (!visit.contains(pos) && robot.move()) {
				dfs(robot, ny, nx, dir);
			}
			robot.turnRight();
			dir = (++dir) % 4;
		}
		back(robot);
	}
	public void cleanRoom(Robot robot) {
		dfs(robot, 0, 0, 0);
	}
}
