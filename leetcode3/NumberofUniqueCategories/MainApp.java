// Copyright (C) 2023 by iamslash

import java.util.*;

interface CategoryHandler {
    boolean haveSameCategory(int a, int b);
};
//             i
//             1 1 2 2 3 3
//             j
// categories: 0 0 2 0 0 0 

// 89ms 100.00% 43.9MB 100.00%
// brute force
// O(N^2) O(N)
class Solution {
    public int numberOfCategories(int n, CategoryHandler categoryHandler) {
        List<Integer> categoryList = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            boolean found = false;
            for (int j : categoryList) {
                if (categoryHandler.haveSameCategory(i, j)) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                categoryList.add(i);
            }
        }
        return categoryList.size();
    }
}
