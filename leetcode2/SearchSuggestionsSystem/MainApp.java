// Copyright (C) 2022 by iamslash

import java.util.*;

// 20ms 86.76% 59.2MB 61.98%
// sort, binary search
// O(NlgN) O(N)
class Solution {
    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        List<List<String>> ans = new ArrayList<>();
        Arrays.sort(products);
        int n = products.length;
        for (int i = 1; i <= searchWord.length(); ++i) {
            String typed = searchWord.substring(0, i);
            int k = Arrays.binarySearch(products, typed);
            // same typed string
            while (k > 0 && typed.equals(products[k-1])) {
                --k;
            }
            if (k < 0) {
                k = ~k;
            }
            List<String> candList = new ArrayList<>();
            for (int j = k; j < Math.min(k+3, n) && products[j].startsWith(typed); ++j) {
                candList.add(products[j]);
            }
            ans.add(candList);
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
