// Copyright (C) 2024 by iamslash

import java.util.*;

// 256ms 9.30% 107.87MB 55.81%
class Matrix3D {

    private int[][][] data;
    private int[][] yy;

    private void update(int x, int y) {
        int cnt = 0, n = data.length;

        for (int z = 0; z < n; ++z) {
            cnt += data[x][y][z];
        }

        yy[x][y] = cnt;
    }

    public Matrix3D(int n) {
        data = new int[n][n][n];
        yy = new int[n][n];
    }
    
    public void setCell(int x, int y, int z) {
        data[x][y][z] = 1;
        update(x, y);
    }
    
    public void unsetCell(int x, int y, int z) {
        data[x][y][z] = 0;
        update(x, y);
    }
    
    public int largestMatrix() {
        int maxCnt = 0, maxX = 0, n = data.length;

        for (int x = 0; x < n; ++x) {
            int cnt = 0;
            for (int y = 0; y < n; ++y) {
                cnt += yy[x][y];
            }
            if (maxCnt <= cnt) {
                maxX = x;
                maxCnt = cnt;
            }
        }

        return maxX;
    }    
}

// 59ms 69.77% 108.36MB 39.53%
// hash map
//       setCell: O(1)
//     unsetCell: O(1)
// largestMatrix: O(N)
class Matrix3D {

    private int[][][] data;
    private int[] cnts;
    private boolean updated = false;
    int maxX;

    public Matrix3D(int n) {
        data = new int[n][n][n];
        cnts = new int[n];
        maxX = n - 1;
    }
    
    public void setCell(int x, int y, int z) {
        updated = true;
        if (data[x][y][z] != 1) {
            cnts[x]++;
        }
        data[x][y][z] = 1;
    }
    
    public void unsetCell(int x, int y, int z) {
        updated = true;
        if (data[x][y][z] != 0) {
            cnts[x]--;
        }
        data[x][y][z] = 0;
    }
    
    public int largestMatrix() {
        if (updated = false) {
            return maxX;
        }

        int n = cnts.length;
        updated = false;
        maxX = n - 1;
        for (int x = n - 1; x >= 0; --x) {
            if (cnts[maxX] < cnts[x]) {
                maxX = x;
            }
        }

        return maxX;
    }    
}
