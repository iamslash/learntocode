// Copyright (C) 2025 by iamslash

import java.util.*;

// 3ms 25.18% 45.16MB 41.91%
// hash set
// O(N) O(N)
class Solution {
    public int[] recoverOrder(int[] order, int[] friends) {
        Set<Integer> friendSet = new HashSet<>();
        List<Integer> filteredList = new ArrayList<>();

        for (int friend : friends) {
            friendSet.add(friend);
        }
        
        for (int participant : order) {
            if (friendSet.contains(participant)) {
                filteredList.add(participant);
            }
        }

        int[] ans = new int[filteredList.size()];
        for (int i = 0; i < filteredList.size(); ++i) {
            ans[i] = filteredList.get(i);
        }

        return ans;        
    }
}

// 2ms 67.64% 45.00MB 61.25%
// hash set
// O(N) O(N)
class Solution {
    public int[] recoverOrder(int[] order, int[] friends) {
        Set<Integer> friendSet = new HashSet<>();
        int[] ans = new int[friends.length];

        for (int friend : friends) {
            friendSet.add(friend);
        }

        int idx = 0;
        for (int id : order) {
            if (friendSet.contains(id)) {
                ans[idx++] = id;
            }
        }        

        return ans;
    }
}
