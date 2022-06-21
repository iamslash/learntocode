// Copyright (C) 2022 by iamslash

import java.util.*;

// step will be slow
// Changed the plan.
class Robot {
    int h = 0;
    int w = 0;
    int dir = 0;
    int[] dirs = new int[]{-1, 0, 1, 0, -1};
    int[] pos = new int[]{0, 0};
    String[] dirStrs = new String[]{"North", "East", "South", "West"};

    public Robot(int width, int height) {
        h = height;
        w = width;
    }
    
    public void step(int num) {
        
    }
    
    public int[] getPos() {
        return pos;
    }
    
    public String getDir() {
        return dirStrs[dir];
    }
}

// 91ms 81.88% 99.2MB 5.80%
// math
// O(1) O(1)
class Robot {
    int w;
    int h;
    int p; // the count of moved path
    
    public Robot(int width, int height) {
        w = width - 1;
        h = height - 1;
        p = 0;
    }
    
    public void step(int num) {
        p += num;
    }
    
    public int[] getPos() {
        int remain = p % (2 * (w + h));
        if (remain <= w) {
            return new int[]{remain, 0};
        }
        remain -= w;
        if (remain <= h) {
            return new int[]{w, remain};
        }
        remain -= h;
        if (remain <= w) {
            return new int[]{w - remain, h};
        }
        remain -= w;
        return new int[]{0, h - remain};
    }
    
    public String getDir() {
        int[] pos = getPos();
        if (p == 0 || pos[1] == 0 && pos[0] > 0) {
            return "East";
        } else if (pos[0] == w && pos[1] > 0) {
            return "North";
        } else if (pos[1] == h && pos[0] < w) {
            return "West";
        }
        return "South";
    }
}

