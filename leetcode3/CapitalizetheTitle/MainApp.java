// Copyright (C) 2022 by iamslash

import java.util.*;

// 26ms 7.57% 40.6MB 30.20%
// brute force
// O(N) O(N)
class Solution {
    private String transform(String s) {
        String rst = s.toLowerCase();
        if (rst.length() <= 2) {
            return rst;
        }
        rst = Character.toUpperCase(rst.charAt(0)) + rst.substring(1);
        return rst;
    }
    public String capitalizeTitle(String title) {
        String[] words = title.split("\\s+");
        StringBuffer ans = new StringBuffer();
        for (String word : words) {
            ans.append(transform(word));
            ans.append(" ");            
        }
        return ans.toString().trim();
    }
}

// 1ms 99.31% 39.3MB 72.08%
// two pointers
// O(N) O(1)
class Solution {
    public String capitalizeTitle(String title) {
        char[] chars = title.toCharArray();
        int i = 0, j = 0, n = chars.length;
        while (j < n) {
            i = j;
            while (j < n && chars[j] != ' ') {
                chars[j] = Character.toLowerCase(chars[j]);
                j++;
            }
            if (j - i > 2) {
                chars[i] = Character.toUpperCase(chars[i]);
            }
            j++;
        }
        return String.valueOf(chars);
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
