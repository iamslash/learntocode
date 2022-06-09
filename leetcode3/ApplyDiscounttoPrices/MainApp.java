// Copyright (C) 2022 by iamslash

import java.util.*;

// 939ms 45.28% 115.1MB 59.48%
// brute force
// O(N) O(N)
class Solution {
    public String discountPrices(String s, int discount) {
        String[] words = s.split(" ");
        for (int i = 0; i < words.length; ++i) {
            String word = words[i], price = word.substring(1);
            if (word.length() > 1 && word.charAt(0) == '$' &&
                valid(price)) {
                words[i] = String.format("$%.2f", Long.parseLong(price) *
                                         (1 - discount / 100.0));
            }
        }
        return String.join(" ", words);
    }
    private boolean valid(String num) {
        for (char c : num.toCharArray()) {
            if (c < '0' || c > '9') {
                return false;
            }
        }
        return true;
    }
}
