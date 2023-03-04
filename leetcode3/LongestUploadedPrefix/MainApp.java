// Copyright (C) 2023 by iamslash

import java.util.*;

// Idea: sorted set
//
// Examples of uploaded video and longest index
//       [1] : 1
//    [1, 2] : 2
// [1, 2, 3] : 3
//       [2] : 0
//       [3] : 0
//    [2, 3] : 0
//
// Let's make a sorted set.
// 0 1 2 3 4
// upload 2, remove that, ans is 0.
// 0 1 3 4
// upload 1, remove that, ans is 1.
// 0 3 4
// upload 0, remove that, ans is 3.
// 3 4

// Idea: brute force
//
// Let's make an array boolean[] uploaded, int longest.
// uploaded[i] == true means i + 1 video was uploaded.
// longest means longest index of video.

// 134ms 13.57% 122.MB 50.23%
// sorted set
//  upload: O(lgN) O(N)
// longest: O(lgN) O(N)
class LUPrefix {
    SortedSet<Integer> prefixSet = new TreeSet<>();
    int size = 0;

    public LUPrefix(int n) {
        for (int i = 0; i < n; ++i) {
            prefixSet.add(i);
        }
        size = n;
    }
    
    public void upload(int video) {
        prefixSet.remove(video - 1);
    }
    
    public int longest() {
        if (prefixSet.isEmpty()) {
            return size;
        }
        return prefixSet.first();
    }
}

// 36ms 91.86% 108.8MB 64.25%
// brute force
//  upload: O(N) O(N)
// longest: O(1) O(N)
class LUPrefix {
    private boolean[] uploaded;
    private int longest;

    public LUPrefix(int n) {
        uploaded = new boolean[n + 1];
        longest = 0;
        uploaded[0] = true;
    }
    
    public void upload(int video) {
        uploaded[video] = true;
        if (video == longest + 1) {
            for (int i = longest + 1; i < uploaded.length; ++i) {
                if (uploaded[i]) {
                    longest = i;
                } else {
                    break;
                }
            }
        }
    }
    
    public int longest() {
        return longest;
    }
}
