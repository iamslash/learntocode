// Copyright (C) 2024 by iamslash

// 128ms 54.32% 86.9MB 47.91%
// brute force
// O(HW) O(HW)
class Solution {
    private boolean validPos(int[][] imgs, int threshold,
                             int begRow, int begCol,
                             int row, int col) {
        if (row - 1 >= begRow &&
            Math.abs(imgs[row - 1][col] - imgs[row][col]) > threshold) {
            return false;
        }
        if (row + 1 <= begRow + 2 &&
            Math.abs(imgs[row + 1][col] - imgs[row][col]) > threshold) {
            return false;
        }
        if (col - 1 >= begCol &&
            Math.abs(imgs[row][col - 1] - imgs[row][col]) > threshold) {
            return false;
        }
        if (col + 1 <= begCol + 2 &&
            Math.abs(imgs[row][col + 1] - imgs[row][col]) > threshold) {
            return false;
        }
        return true;
    }
    private int getAvg(int[][] imgs, int threshold, int row, int col) {
        int rst = 0;
        for (int y = row; y < row + 3; ++y) {
            for (int x = col; x < col + 3; ++x) {
                if (!validPos(imgs, threshold, row, col, y, x)) {
                    return -1;
                }
                rst += imgs[y][x];
            }
        }
        return rst / 9;
    }
    private void updateAvg(int threshold,
                           int[][] dstImgs, int[][] dstCnts,
                           int avg, int row, int col) {
        for (int y = row; y < row + 3; ++y) {
            for (int x = col; x < col + 3; ++x) {
                dstImgs[y][x] += avg;
                dstCnts[y][x]++;
            }
        }
    }
    public int[][] resultGrid(int[][] image, int threshold) {
        int h = image.length, w = image[0].length;
        int[][] ans = new int[h][w];
        int[][] cnts = new int[h][w];
        for (int y = 0; y <= h - 3; ++y) {
            for (int x = 0; x <= w - 3; ++x) {
                int avg = getAvg(image, threshold, y, x);
                if (avg >= 0) {
                    updateAvg(threshold, ans, cnts, avg, y, x);
                }
            }
        }
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (cnts[y][x] > 0) {
                    ans[y][x] /= cnts[y][x];
                } else {
                    ans[y][x] = image[y][x];
                }
            }
        }
        return ans;                                    
    }
}
