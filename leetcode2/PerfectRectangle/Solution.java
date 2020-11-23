// Copyright (C) 2020 by iamslash

import java.util.Set;
import java.util.HashSet;

// 307ms 11.49% 47.6MB 100.00%
// match
// O(HW) O(HW)
class Solution {
	public boolean isRectangleCover(int[][] R) {
		int sumArea = 0, outArea = 0;
		Set<String> posSet = new HashSet<>();
		int[] outPos = {R[0][0], R[0][1], R[0][2], R[0][3]};
		String lbStr, ltStr, rbStr, rtStr;
		for (int[] pos : R) {
			outPos[0] = Math.min(outPos[0], pos[0]);
			outPos[1] = Math.min(outPos[1], pos[1]);
			outPos[2] = Math.max(outPos[2], pos[2]);
			outPos[3] = Math.max(outPos[3], pos[3]);

			int area = (pos[2] - pos[0]) * (pos[3] - pos[1]);
			sumArea += area;
			// System.out.printf("%d\n", area);

			lbStr = String.format("%d %d", pos[0], pos[1]);
			ltStr = String.format("%d %d", pos[0], pos[3]);
			rbStr = String.format("%d %d", pos[2], pos[1]);
			rtStr = String.format("%d %d", pos[2], pos[3]);

			// Remove duplicates
			if (!posSet.add(lbStr))
				posSet.remove(lbStr);
			if (!posSet.add(ltStr))
				posSet.remove(ltStr);
			if (!posSet.add(rbStr))
				posSet.remove(rbStr);
			if (!posSet.add(rtStr))
				posSet.remove(rtStr);
		}

		lbStr = String.format("%d %d", outPos[0], outPos[1]);
		ltStr = String.format("%d %d", outPos[0], outPos[3]);
		rbStr = String.format("%d %d", outPos[2], outPos[1]);
		rtStr = String.format("%d %d", outPos[2], outPos[3]);

		// Check included in posSet
		if (!posSet.contains(lbStr) ||
				!posSet.contains(ltStr) ||
				!posSet.contains(rbStr) ||
				!posSet.contains(rtStr) ||
				posSet.size() != 4)
			return false;
		
		return sumArea == (outPos[2] - outPos[0]) * (outPos[3] - outPos[1]);
	}
	public static void main(String[] args) {
		int[][] R = {
			{0, 0, 2, 2},
			{1, 1, 3, 3},
			{2, 0, 3, 1},
			{0, 3, 3, 4}};
		Solution sln = new Solution();
		System.out.printf("%b\n", sln.isRectangleCover(R));
	}
}
