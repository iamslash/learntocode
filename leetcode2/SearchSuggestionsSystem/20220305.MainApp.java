// Copyright (C) 2022 by iamslash

import java.util.*;

// 10ms 97.80% 45.6MB 90.69%
// sort, binary search
// O(NlgN) O(N)
class Solution {
    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        int n = products.length;
        List<List<String>> ans = new ArrayList<>();
        Arrays.sort(products);
        for (int i = 1; i <= searchWord.length(); ++i) {
            String cur = searchWord.substring(0, i);
            int k = Arrays.binarySearch(products, cur);
            // find first one when same curs
            while (k > 0 && cur.equals(products[k-1])) {
                --k;
            }
            if (k < 0) {
                k = ~k;
            }
            List<String> candList = new ArrayList<>();
            for (int j = k; j < Math.min(k+3, n) && products[j].startsWith(cur); ++j) {
                candList.add(products[j]);
            }
            ans.add(candList);
        }
        return ans;
    }
}

public class MainApp {
    private static void dump(String[] ss) {
        for (String s : ss) {
            System.out.printf("%s ", s);
        }
        System.out.println("");
    }
    public static void main(String[] args) {
        String[] products = {"mobile","mouse","moneypot","monitor","mousepad"};
        String searchWord = "mouse";
        Arrays.sort(products);
        dump(products);
        for (int i = 1; i <= searchWord.length(); ++i) {
            String word = searchWord.substring(0, i);
            System.out.printf("%2d: %s\n",
                              Arrays.binarySearch(products, word), word);
        }
    }
}
