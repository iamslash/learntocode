// Copyright (C) 2021 by iamslash

import java.util.*;

// box:
//      
//      # . * .  
//      # # * .
//          x
// dsx: 0 0 0 1
//
// ans:
//      # . 
//      # # 
//      * * 
//      . . 

// 12ms 73.25% 65.7MB 99.51%
// matrix
// O(HW) O(HW)
class Solution {
	public char[][] rotateTheBox(char[][] box) {
		int n = box.length, m = box[0].length;
		char[][] ans = new char[m][n];
		for (int y = 0; y < m; ++y) {
			Arrays.fill(ans[y], '.');
		}
		for (int y = 0; y < n; ++y) {
			int[] dxs = new int[m];
			for (int dx = 0, x = m-1; x >= 0; --x) {
				if (box[y][x] == '.') {
					dx++;
				} else if (box[y][x] == '*') {
					dx = 0;
				} 
				dxs[x] = dx;
			}
			for (int x = 0; x < m; ++x) {
				if (box[y][x] == '.') {
					continue;
				}
				int nx = x;
				if (box[y][x] == '#') {
					nx += dxs[x];
				}
				ans[nx][n-y-1] = box[y][x];				
			}
		}
		return ans;
	}
}

// 9ms 97.18% 75.7MB 60.70%
// matrix
// O(HW) O(HW)
class Solution {
	public char[][] rotateTheBox(char[][] box) {
		int m = box.length, n = box[0].length;
		char[][] ans = new char[n][m];
		for (int y = 0; y < m; ++y) {
			for (int x = n-1, k = n-1; x >=0; --x) {
				ans[x][m-y-1] = '.';
				if (box[y][x] != '.') {
					k = box[y][x] == '*' ? x : k;
					ans[k--][m-y-1] = box[y][x];
				}
			}
		}
		return ans;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
