// Copyright (C) 2022 by iamslash

import java.util.*;

// // 20ms 94.09% 77.5MB 54.55%
// // two pointers
// // O(N) O(N)
// class Solution {
//     public String addSpaces(String s, int[] spaces) {
//         StringBuilder sb = new StringBuilder();
//         for (int i = 0, j = 0; i < s.length(); ++i) {
//             if (j < spaces.length && i == spaces[j]) {
//                 sb.append(' ');
//                 j++;
//             }
//             sb.append(s.charAt(i));
//         }
//         return sb.toString();
//     }
// }

// 17ms 95.65% 98.5MB 47.83%
// two pointers
// O(N) O(N)
class Solution {
    public String addSpaces(String s, int[] spaces) {
        char[] srcChars = s.toCharArray();
        char[] dstChars = new char[srcChars.length + spaces.length];
        for (int i = 0, j = 0; i < srcChars.length; ++i) {
            if (j < spaces.length && i == spaces[j]) {
                dstChars[i+j] = ' ';
                j++;
            }
            dstChars[i+j] = srcChars[i];
        }
        return new String(dstChars);
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
