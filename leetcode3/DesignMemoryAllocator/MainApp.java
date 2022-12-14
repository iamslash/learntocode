// Copyright (C) 2022 by iamslash

import java.util.*;

//
//       s  
// data: -
//       e
//       

// 37ms 66.41% 43.4MB 76.11%
// brute force
// allocate: O(N)
//     free: O(N)
class Allocator {
    private int[] data;

    public Allocator(int n) {
        data = new int[n];
        Arrays.fill(data, -1);
    }
    
    public int allocate(int size, int mID) {
        if (size > data.length) {
            return -1;
        }
        int cnt = 0, s = 0, e = 0;
        for (int i = 0; i < data.length; ++i) {
            if (data[i] == -1) {
                cnt++;
            } else {
                cnt = 0;
                s = i + 1;
            }
            if (cnt == size) {
                e = i;
                break;
            }
        }
        if (s > e) {
            return -1;
        }
        Arrays.fill(data, s, e + 1, mID);
        return s;
    }
    
    public int free(int mID) {
        int cnt = 0;
        for (int i = 0; i < data.length; ++i) {
            if (data[i] == mID) {
                cnt++;
                data[i] = -1;
            }
        }
        return cnt;
    }
}
