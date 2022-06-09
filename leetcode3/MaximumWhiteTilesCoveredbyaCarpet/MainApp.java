// Copyright (C) 2022 by iamslash

import java.util.*;

//         b
//  tiles: 1,5 10,11 12,18 20,25 30,32
//           e
// maxLen:   

// sort
// O(NlgN) O(1)
class Solution {
    public int maximumWhiteTiles(int[][] tiles, int carpetLen) {
        Arrays.sort(tiles, (a, b) -> a[0] - b[0]);
        int maxLen = 0, n = tiles.length, prvBeg = -1, prvEnd = -1;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || prvEnd + 1 != tiles[i][0]) {
                prvBeg = tiles[i][0];
            }
            prvEnd = tiles[i][1];
            maxLen = Math.max(maxLen, Math.min(prvEnd - prvBeg + 1, carpetLen));
        }
        return maxLen;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
