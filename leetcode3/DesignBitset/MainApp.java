// Copyright (C) 2022 by iamslash

import java.util.*;

// 234ms 16.19% 146.7MB 18.09%
// hash set
//      fix: O(1)
//    unfix: O(1)
//     flip: O(1)
//      all: O(1)
//      one: O(1)
//    count: O(1)
// toString: O(N)
class Bitset {
    private int len;
    private Set<Integer> oneIdxSet = new HashSet<>();
    private Set<Integer> zeroIdxSet = new HashSet<>();
    public Bitset(int size) {
        len = size;
        for (int i = 0; i < len; ++i) {
            zeroIdxSet.add(i);
        }
    }    
    public void fix(int idx) {
        oneIdxSet.add(idx);
        zeroIdxSet.remove(idx);
    }
    public void unfix(int idx) {
        zeroIdxSet.add(idx);
        oneIdxSet.remove(idx);
    }    
    public void flip() {
        Set<Integer> tmpSet = oneIdxSet;
        oneIdxSet = zeroIdxSet;
        zeroIdxSet = tmpSet;
    }    
    public boolean all() {
        return zeroIdxSet.size() == 0;
    }    
    public boolean one() {
        return oneIdxSet.size() > 0;
    }    
    public int count() {
        return oneIdxSet.size();
    }    
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < len; ++i) {
            if (oneIdxSet.contains(i)) {
                sb.append("1");
            } else if (zeroIdxSet.contains(i)) {
                sb.append("0");
            }
        }
        return sb.toString();
    }
}

// 117ms 48.25% 143MB 53.97%
// array
//      fix: O(1)
//    unfix: O(1)
//     flip: O(1)
//      all: O(1)
//      one: O(1)
//    count: O(1)
// toString: O(N)
class Bitset {
    private int oneCnt = 0;
    private boolean isFlip = false;
    private char[] data;
    public Bitset(int size) {
        data = new char[size];
        Arrays.fill(data, '0');
    }
    public void fix(int idx) {
        if (!isFlip && data[idx] == '0') {
            oneCnt++;
            data[idx] = '1';
        } else if (isFlip && data[idx] == '1') {
            oneCnt++;
            data[idx] = '0';
        }
    }
    public void unfix(int idx) {
        if (!isFlip && data[idx] == '1') {
            oneCnt--;
            data[idx] = '0';
        } else if (isFlip && data[idx] == '0') {
            oneCnt--;
            data[idx] = '1';
        }
    }
    public void flip() {
        isFlip = !isFlip;
        oneCnt = data.length - oneCnt;
    }
    public boolean all() {
        return oneCnt == data.length;
    }
    public boolean one() {
        return oneCnt > 0;
    }
    public int count() {
        return oneCnt;
    }    
    public String toString() {
        if (isFlip) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < data.length; ++i) {
                if (data[i] == '1') {
                    sb.append("0");
                } else {
                    sb.append("1");
                }
            }
            return sb.toString();
        } 
        return String.valueOf(data);
    }
}
