// Copyright (C) 2020 by iamslash

// 26ms 100.00% 37.8MB 50.00%
// brute force
// O(XYT) O(1)
class Solution {
	public int[] bestCoordinate(int[][] towers, int radius) {
		int maxQ = 0, maxX = 0, maxY = 0;
		for (int x = 0; x <= 50; ++x) {
			for (int y = 0; y <= 50; ++y) {
				int quality = 0;
				for (int j = 0; j < towers.length; ++j) {
					int xd = x - towers[j][0];
					int yd = y - towers[j][1];
					double d = Math.sqrt(xd * xd + yd * yd);
					if (d <= (double)radius) {
						quality += (int)(towers[j][2] / (1 + d));
					}
				}
				if (quality > maxQ) {
					maxQ = quality;
					maxX = x;
					maxY = y;
				}
			}
		}
		return new int[]{maxX, maxY};
	}
}
