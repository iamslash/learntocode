// Copyright (C) 2021 by iamslash

import java.util.*;

// h: 3, w: 3 
// ch
//  ie
//   pr

// 38ms 78.43% 47.6MB 93.45%
// math
// O(N) O(1)
class Solution {
    public String decodeCiphertext(String encodedText, int h) {
        int n = encodedText.length(), w = n / h;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < w; ++i) {
            int y = 0, x = i;
            while (y < h && x < w) {
                int idx = y * w + x;
                sb.append(encodedText.charAt(idx));
                ++y;
                ++x;
            }
        }
        // trim right
        int last = sb.length()-1;
        while (last >= 0 && sb.charAt(last) == ' ') {
            sb.deleteCharAt(last--);
        }
        return sb.toString();
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
