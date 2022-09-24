// Copyright (C) 2022 by iamslash

import java.util.*;

//     k: 4
// rolls: 4 2 1 2 3 3 2 4 1
//                i
//   set: 
//   ans: 1

// Idea: hash set
//
// Make a group whose count is k.
// The answer is failed group count.
//
// rolls: 4 2 1 2 3 3 2 4 1
//        ---------
//                  -------
// failed group count is 3rd.

// 70ms 15.15% 110.6MB 33.39%
// hash set
// O(N) O(K)
class Solution {
    public int shortestSequence(int[] rolls, int k) {
        int ans = 1;
        Set<Integer> diceSet = new HashSet<>();
        for (int roll : rolls) {
            diceSet.add(roll);
            if (diceSet.size() == k) {
                diceSet.clear();
                ans++;
            }
        }
        return ans;
    }
}
