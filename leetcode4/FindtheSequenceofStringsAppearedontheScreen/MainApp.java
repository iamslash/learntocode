// Copyright (C) 2024 by iamslash

import java.util.*;

// // 14ms 24.62% 55.67MB 49.39%
// // brute force
// // O(N) O(N)
// class Solution {
//     public List<String> stringSequence(String target) {
//         List<String> ans = new ArrayList<>();
//         StringBuilder sb = new StringBuilder();
        
//         for (char c : target.toCharArray()) {
//             char d = 'a';

//             while (c >= d) {
//                 ans.add(sb.toString() + d);
//                 d++;                
//             }

//             sb.append(c);
//         }

//         return ans;
//     }
// }

// 5ms 100.00% 55.54MB 65.29%
// brute force
// O(N) O(N)
class Solution {
    public List<String> stringSequence(String target) {
        List<String> ans = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        
        for (char c : target.toCharArray()) {
            sb.append('a');
            ans.add(sb.toString());

            char d = 'a';
            while (c != d) {
                d = (char)('a' + ((d - 'a' + 1) % 26 ));
                sb.setCharAt(sb.length() - 1, d);
                ans.add(sb.toString());
            }

        }

        return ans;
    }
}
