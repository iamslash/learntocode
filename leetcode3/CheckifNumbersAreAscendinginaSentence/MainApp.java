// Copyright (C) 2021 by iamslash

import java.util.*;

// 3ms 42.86% 38.9MB 57.14%
// brute force
// O(N) O(N)
class Solution {
    public boolean areNumbersAscending(String s) {
        String[] ss = s.split(" ");
        int minNum = 0;
        for (String word : ss) {
            try {
                int num = Integer.parseInt(word);
                if (num <= minNum) {
                    return false;
                }
                // System.out.printf("minNum: %d, num: %d\n", minNum, num);
                minNum = Math.max(minNum, num);                
            } catch (Exception e) {
                continue;
            }
        }
        return true;
    }
}

//                          i
//      s: sdfsdf 5 sdfsdf 5
// prvNum: 5
// curNum: 5

// 0ms 100.00% 37.1MB 85.71%
// brute force
// O(N) O(1)
class Solution {
    public boolean areNumbersAscending(String s) {
        int n = s.length(), prvNum = -1, curNum = 0;
        for (int i = 0; i < n; ++i) {
            char c = s.charAt(i);
            if (Character.isDigit(c)) {
                curNum = curNum*10 + (c-'0');
            } else if (curNum > 0 && curNum <= prvNum) {
                return false;
            } else {
                if (curNum > 0) {
                    prvNum = curNum;
                    curNum = 0;
                }
            }               
        }
        return curNum == 0 || curNum > prvNum;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
