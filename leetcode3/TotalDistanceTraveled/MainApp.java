// Copyright (C) 2023 by iamslash

import java.util.*;

//       mainTank: 9
// additionalTank: 10
//
//              x:

// 9ms 15.62% 43.4MB 12.13%
// brute force
// O(N) O(1)
class Solution {
    public int distanceTraveled(int mainTank, int additionalTank) {
        int ans = 0;
        for (int i = 1; i <= mainTank; ++i) {
            if (additionalTank > 0 && i % 5 == 0) {
                additionalTank -= 1;
                mainTank += 1;
            }
            ans += 10;
        }
        return ans;
    }    
}

// Idea: math
//
// extraTank: tank to be added to mainTank
// extraTank <= additionalTank
// 4 * extraTank <= mainTank 
//
// M  M  M  M  M   A  M  M  M  M    A   M  M  M  M   A
// 1 [2  3  4  5]  6 [7  8  9 10]  11 [12 13 14 15] 16
//
// M stands for mainTank, A stands for additionalTank.
// The first liter is outside of the cycle, and then we have a cycle
// of length 4, i.e., for every 4 liters from the mainTank we can add
// 1 liter from the additionalTank.
//
// F(M, A) = 10 * (M + min((M - 1) / 4, A))

// 7ms 100.00% 43.2MB 60.00%
// math
// O(1) O(1)
class Solution {
    public int distanceTraveled(int mainTank, int additionalTank) {
        int extraTank = Math.min((mainTank - 1) / 4, additionalTank);
        return (mainTank + extraTank) * 10;
    }
}
