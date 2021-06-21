// Copyright (C) 2021 by iamslash

// // 2ms 25.27% 85.2MB 13.55%
// // brute force
// // O(HW) O(1)
// class Solution {
// 	public int[] findPeakGrid(int[][] mat) {
// 		int maxNum = mat[0][0], maxY = 0, maxX = 0;
// 		int h = mat.length, w = mat[0].length;
// 		for (int y = 0; y < h; ++y) {
// 			for (int x = 0; x < w; ++x) {
// 				if (maxNum < mat[y][x]) {
// 					maxNum = mat[y][x];
// 					maxY = y;
// 					maxX = x;
// 				}
// 			}
// 		}
// 		return new int[]{maxY, maxX};
// 	}
// }

// 0ms 100.00% 85MB 33.70%
// binary search
// O(HlgW)
// binary search
class Solution {
	public int[] findPeakGrid(int[][] mat) {
		int h = mat.length, w = mat[0].length;
		int loX = 0, hiX = w - 1;
		while (loX <= hiX) {
			int miX = (loX + hiX) / 2;
			int maxY = 0;
			for (int y = 0; y < h; ++y) {
				if (mat[y][miX] > mat[maxY][miX]) {
					maxY = y;
				}
			}
			boolean isLeftElementBig = miX - 1 >= loX &&
					mat[maxY][miX-1] > mat[maxY][miX];
			boolean isRightElementBig = miX + 1 <= hiX &&
					mat[maxY][miX] < mat[maxY][miX+1];
			if (!isLeftElementBig && !isRightElementBig) {
				return new int[]{maxY, miX};				
			} else if (isRightElementBig) {
				loX = miX + 1;
			} else {
				hiX = miX - 1;
			}
		}
	  return null;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
