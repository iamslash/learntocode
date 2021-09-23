// Copyright (C) 2021 by iamslash

import java.util.*;

// 0ms 100.00% 36.8MB 86.79%
// brute force
// O(N) O(1)
public class Solution extends Reader4 {
    public int read(char[] dst, int n) {
        char[] buf4 = new char[4];
        int dstPos = 0, readCnt = 0;
        while (n > 0) {
            readCnt = Math.min(read4(buf4), n);
            if (readCnt == 0) {
                break;
            }
            System.arraycopy(buf4, 0, dst, dstPos, readCnt);
            dstPos += readCnt;
            n -= readCnt;            
        }
        return  dstPos;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
