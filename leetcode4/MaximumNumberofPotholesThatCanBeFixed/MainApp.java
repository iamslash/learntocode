// Copyright (C) 2024 by iamslash

import java.util.*;

// 34ms 88.68% 45.8MB 13.21%
// sort
// O(NlgN) O(N)
class Solution {
    private void dump(int[] A) {
        for (int a : A) {
            System.out.printf("%d ", a);
        }
        System.out.println();
    }
    
    public int maxPotholes(String road, int budget) {
        int n = road.length(), holeCnt = 0, pos = 0;
        int[] holeCnts = new int[n];
        for (char c : road.toCharArray()) {
            if (c == 'x') {
                holeCnt++;
            } else {
                holeCnts[pos++] = holeCnt;
                holeCnt = 0;
            }
        }
        if (holeCnt > 0) {
            holeCnts[pos] = holeCnt;
        }

        Arrays.sort(holeCnts);
        
        // dump(holeCnts);

        int fixedHoles = 0;
        for (int i = n - 1; i >= 0 && holeCnts[i] > 0 && budget > 0; --i) {
            int cost = holeCnts[i] + 1;
            int capa = cost <= budget ? cost : budget;
            fixedHoles += capa - 1;
            budget -= capa;
        }

        return fixedHoles;
    }
}
