// Copyright (C) 2022 by iamslash

import java.util.*;

//         i
//      s: ababcbacadefegdehijhklij
//                 j
// maxIdx: 8
//  lasts: a
//         8
//        

// 3ms 88.15% 37.7MB 75.50%
// two pointers
// O(N) O(1)
class Solution {
  public List<Integer> partitionLabels(String s) {   
    int n = s.length();
    int[] lasts = new int[26];
    for (int i = 0; i < n; ++i) {
      int pos = s.charAt(i) - 'a';
      lasts[pos] = Math.max(lasts[pos], i);
    }
    List<Integer> ans = new ArrayList<>();
    int maxLast = 0, i = 0, j = 0;
    while (j < n) {
      int pos = s.charAt(j) - 'a';
      maxLast = Math.max(maxLast, lasts[pos]);
      if (maxLast == j) {
        ans.add(j - i + 1);
        i = j + 1;
        maxLast = i;          
      }
      j++;
    }
    return ans;
  }
}
 
public class MainApp {
  public static void main(String[] args) {
  }
}
