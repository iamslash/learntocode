// Copyright (C) 2024 by iamslash

import java.util.*;

// 3ms 90.55% 42.8MB 28.88%
// brute force
// O(N) O(N)
class Solution {
    public String convertDateToBinary(String date) {
        String[] chars = date.split("-");
        StringBuilder sb = new StringBuilder();

        sb.append(Integer.toBinaryString(Integer.parseInt(chars[0])));
        sb.append("-");
        sb.append(Integer.toBinaryString(Integer.parseInt(chars[1])));
        sb.append("-");
        sb.append(Integer.toBinaryString(Integer.parseInt(chars[2])));

        return sb.toString();
    }
}

// 1ms 100.00% 42.4MB 76.69%
// brute force
// O(N) O(N)
class Solution {
    public String convertDateToBinary(String date) {

        String yearStr = date.substring(0, 4);
        String dateStr = date.substring(5, 7);
        String timeStr = date.substring(8, 10);
        
        StringBuilder sb = new StringBuilder();
        sb.append(Integer.toBinaryString(Integer.parseInt(yearStr)));
        sb.append("-");
        sb.append(Integer.toBinaryString(Integer.parseInt(dateStr)));
        sb.append("-");
        sb.append(Integer.toBinaryString(Integer.parseInt(timeStr)));

        return sb.toString();
    }
}
