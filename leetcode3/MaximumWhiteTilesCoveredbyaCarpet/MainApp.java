// Copyright (C) 2022 by iamslash

import java.util.*;

//         b
//  tiles: 1,5 10,11 12,18 20,25 30,32
//           e
// maxLen:

// ========
// ----- -----
//     i     j

// ========
// ----- --
//     i  j

// 76ms 68.18% 75.2MB 84.20%
// sort, sliding window
// O(NlgN) O(1)
class Solution {
    public int maximumWhiteTiles(int[][] tiles, int carpetLen) {
        Arrays.sort(tiles, (a, b) -> a[0] - b[0]);
        int maxLen = 0, covered = 0, i = 0, j = 0, n = tiles.length;
        while (maxLen < carpetLen && j < n) {
            if (i == j ||
                tiles[i][0] + carpetLen > tiles[j][1]) {
                covered += Math.min(carpetLen, tiles[j][1] - tiles[j][0] + 1);
                maxLen = Math.max(maxLen, covered);
                j++;
            } else {
                int part = Math.max(0, tiles[i][0] + carpetLen - tiles[j][0]);
                maxLen = Math.max(maxLen, covered + part);
                covered -= (tiles[i][1] - tiles[i][0] + 1);
                i++;
            }
        }
        return maxLen;
    }
}
