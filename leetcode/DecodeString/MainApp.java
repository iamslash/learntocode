// Copyright (C) 2024 by iamslash

import java.util.*;

// 1ms 77.21% 41.7MB 36.82%
// stack
// O(N) O(N)
class StckItem {
    public int cnt;
    public StringBuilder sb = new StringBuilder();
    public StckItem(int cnt) {
        this.cnt = cnt;
    }
}
class Solution {
    public String decodeString(String s) {
        Stack<StckItem> stck = new Stack<>();
        stck.push(new StckItem(0));
        StringBuilder cntSb = new StringBuilder();

        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (c >= '0' && c <= '9') {
                cntSb.append(c);
            } else if (c == '[') {
                stck.push(new StckItem(Integer.parseInt(cntSb.toString())));
                cntSb = new StringBuilder();
            } else if (c == ']') {
                StckItem item = stck.pop();
                int cnt = item.cnt;
                while (cnt-- > 0) {
                    stck.peek().sb.append(item.sb.toString());
                }
            } else {
                stck.peek().sb.append(c);
            }
        }

        return stck.peek().sb.toString();            
    }
}
