// Copyright (C) 2023 by iamslash

import java.util.*;

// a: abc
// b:  bcd

// 45ms 59.73% 44.3MB 63.58%
// brute foce
// O(ABC) O(ABC)
class Solution {
    private String merge(String a, String b) {
        if (a.indexOf(b) >= 0) {
            return a;
        }
        int n = a.length(), m = b.length(), bnd = Math.min(n, m);
        for (int i = bnd - 1; i > 0; --i) {
            if (a.substring(n - i).equals(b.substring(0, i))) {
                return a + b.substring(i);
            }
        }
        return a + b;
    }
    private String merge(String a, String b, String c) {
        return merge(merge(a, b), c);
    }
    public String minimumString(String a, String b, String c) {
        List<String> strList = new ArrayList<>();
        strList.add(merge(a, b, c));
        strList.add(merge(a, c, b));
        strList.add(merge(b, a, c));
        strList.add(merge(b, c, a));
        strList.add(merge(c, a, b));
        strList.add(merge(c, b, a));
        Collections.sort(strList, (lhs, rhs) -> {
                if (lhs.length() == rhs.length()) {
                    return lhs.compareTo(rhs);
                }
                return lhs.length() - rhs.length();
            });
        return strList.get(0);
    }
}
