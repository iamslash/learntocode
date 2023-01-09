// Copyright (C) 2023 by iamslash

import java.util.*;

// 31ms 83.33% 80.3MB 50.00%
// consec: O(1) O(1)
class DataStream {
    private int value = 0;
    private int k = 0;
    private int cnt = 0;
    
    public DataStream(int value, int k) {
        this.value = value;
        this.k = k;
    }
    
    public boolean consec(int num) {
        if (value == num) {
            cnt++;
        } else {
            cnt = 0;
        }
        return cnt >= k;
    }
}
