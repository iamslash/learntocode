// Copyright (C) 2023 by iamslash

//          i
//   s: string
// buf: str
// ans:

// 3ms 100.00% 43.5MB 100.00%
// brute force
// O(N) O(N)
class Solution {
    public String finalString(String s) {
        StringBuilder buf = new StringBuilder();
        int n = s.length(), i = 0, iCnt = 0;
        while (i < n) {
            while (i < n && s.charAt(i) == 'i') {
                i++;
                iCnt++;
            }
            if (iCnt > 0 && !buf.isEmpty()) {
                if (iCnt % 2 == 1) {
                    buf.reverse();
                }
            } else {
                buf.append(s.charAt(i));
                i++;
            }
            iCnt = 0;
            // System.out.printf("i: %d, buf: %s\n", i, buf.toString());
        }
        return buf.toString();
    }
}
