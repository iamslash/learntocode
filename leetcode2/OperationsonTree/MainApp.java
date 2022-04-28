// Copyright (C) 2022 by iamslash

import java.util.*;

// Idea:
// int[] parents for parent node
// Map<Integer, Integer> lockerMap for {num: user}
// Map<Integer, List<Integer>> childMap for {num: [num,...]}

// 349ms 26.67% 146.1MB 13.33%
// hash map
class LockingTree {
    private int[] parents;
    Map<Integer, Integer> lockerMap = new HashMap<>();
    Map<Integer, List<Integer>> childMap = new HashMap<>();
    public LockingTree(int[] parent) {
        parents = parent;
        for (int u = 0; u < parents.length; ++u) {
            childMap.putIfAbsent(parents[u], new ArrayList<>());
            childMap.get(parents[u]).add(u);
        }
    }
    
    public boolean lock(int num, int user) {
        if (!lockerMap.containsKey(num)) {
            lockerMap.put(num ,user);
            return true;
        }
        return false;
    }
    
    public boolean unlock(int num, int user) {
        if (lockerMap.containsKey(num) &&
            lockerMap.get(num) == user) {
            lockerMap.remove(num);
            return true;
        }
        return false;
    }
    
    public boolean upgrade(int num, int user) {
        // Check locker
        if (lockerMap.containsKey(num)) {
            return false;
        }
        // Check ancestor
        int cur = num;
        while (parents[cur] != -1) {
            if (lockerMap.containsKey(parents[cur])) {
                return false;
            }
            cur = parents[cur];
        }
        // Check decendents
        Queue<Integer> q = new LinkedList<>();
        List<Integer> childList = childMap.get(num);
        if (childList != null) {
            for (int child : childList) {
                q.offer(child);
            }
        }
        boolean locked = false;
        while (!q.isEmpty()) {
            int u = q.poll();
            if (lockerMap.containsKey(u)) {
                locked = true;
                lockerMap.remove(u);
            }
            List<Integer> vList = childMap.get(u);
            if (vList != null) {
                for (int v : vList) {
                    q.offer(v);
                }
            }
        }
        // No locker
        if (!locked) {
            return false;
        }
        // Lock the num
        lockerMap.put(num, user);
        return true;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
