// Copyright (C) 2021 by iamslash

// DFS
// O(N) O(N)
class Solution {
    private int cnt = 0;
    private int[] dir = {-1, 0, 1, 0, -1};
    private void dfs(int[][] room, int y, int x) {
        int h = room.length, w = room[0].length;
        // base
        room[y][x] = -1;
        cnt++;
        // recursion
        for (int i = 0; i < 4; ++i) {
            int ny = y + dir[i], nx = x + dir[i+1];
            if (ny < 0 || ny >= h || nx < 0 || nx >= w ||
                room[ny][nx] != 0) {
                continue;
            }
            dfs(room, ny, nx);
        }
    }
    public int numberOfCleanRooms(int[][] room) {
        dfs(room, 0, 0);
        return cnt;
    }
}
