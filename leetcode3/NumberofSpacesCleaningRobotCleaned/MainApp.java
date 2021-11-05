// Copyright (C) 2021 by iamslash

import java.util.*;

// 0 0 0
// 0 0 0
// 0 0 0

// Time Limit Exceed
// simulate, DFS
// O(N) O(N)
class Solution {
    private int[] dir = {0, 1, 0, -1, 0};
    private boolean canMove(int[][] room, int y, int x) {
        int h = room.length, w = room[0].length;
        return y >= 0 && y < h && x >= 0 && x < w &&
            room[y][x] == 0;
    }
    public int numberOfCleanRooms(int[][] room) {
        int h = room.length, w = room[0].length;
        int y = 0, x = 0, d = 0;     
        Set<int[]> visited = new HashSet(); // [y, x, d]
        Set<int[]> cleaned = new HashSet(); // [y, x]
        cleaned.add(new int[]{0, 0});
        while (visited.add(new int[]{y, x, d})) {
            while(canMove(room, y + dir[d], x + dir[d+1])) {
                y += dir[d];
                x += dir[d+1];
                if (!visited.add(new int[]{y, x, d})) {
                    return cleaned.size();
                }
                cleaned.add(new int[]{y, x});
            }
            d = (d + 1) % 4;
        }
        return cleaned.size();
    }
}

// 1ms 100.00% 49MB 100.00%
// simulate, DFS
// O(N) O(N)
class Solution {
    private int[] dir = {0, 1, 0, -1, 0};
    private boolean canMove(int[][] room, int y, int x) {
        int h = room.length, w = room[0].length;
        return y >= 0 && y < h && x >= 0 && x < w &&
            room[y][x] == 0;
    }
    public int numberOfCleanRooms(int[][] room) {
        int h = room.length, w = room[0].length;
        int y = 0, x = 0, d = 0;     
        Set<List<Integer>> visited = new HashSet(); // [y, x, d]
        Set<List<Integer>> cleaned = new HashSet(); // [y, x]
        cleaned.add(List.of(0, 0));
        while (visited.add(List.of(y, x, d))) {
            while(canMove(room, y + dir[d], x + dir[d+1])) {
                y += dir[d];
                x += dir[d+1];
                if (!visited.add(List.of(y, x, d))) {
                    return cleaned.size();
                }
                cleaned.add(List.of(y, x));
            }
            d = (d + 1) % 4;
        }
        return cleaned.size();
    }
}

class MainApp {
    public static void main(String[] args) {
        Set<int[]> aSet = new HashSet();
        Set<List<Integer>> bSet = new HashSet();
        aSet.add(new int[]{1, 2, 3});
        System.out.println(aSet.add(new int[]{1, 2, 3})); // true
        bSet.add(List.of(1, 2, 3));
        System.out.println(bSet.add(List.of(1, 2, 3)));   // false
    }
}
