// Copyright (C) 2022 by iamslash

import java.util.*;

// 105ms 98.81% 73.5MB 83.33%
// tree
// O(N) O(N)
class Folder {
    String name;
    Map<String, Folder> dirMap;
    List<Folder> dirList;
    String key;
    boolean del;
    
    Folder(String name) {
        this.name = name;
        dirMap = new HashMap<>();
        dirList = new ArrayList<>();
        key = "";
        del = false;
    }
}
class Solution {
    Folder root = new Folder("");
    // {key : count of key}
    Map<String, Integer> keyMap = new HashMap<>();

    private boolean isValid(List<String> path) {
        Folder cur = root;
        for (String dir : path) {
            cur = cur.dirMap.get(dir);
            if (cur.del) {
                return false;
            }
        }
        return true;
    }
    private void updateDeleteStatus(Folder f) {
        // base
        if (f.dirList.size() > 0 && keyMap.get(f.key) > 1) {
            f.del = true;
            return;
        }
        // recursion
        for (Folder child : f.dirList) {
            updateDeleteStatus(child);
        }
    }
    private String generateKey(Folder f) {
        StringBuilder sb = new StringBuilder();
        // base
        if (f.dirList.size() == 0) {
            return sb.toString();
        }
        // recursion
        Collections.sort(f.dirList, (a, b) -> a.name.compareTo(b.name));
        for (Folder child : f.dirList) {
            sb.append('(');
            sb.append(child.name + generateKey(child));
            sb.append(')');
        }
        String key = sb.toString();
        f.key = key;        
        keyMap.put(key, keyMap.getOrDefault(key, 0) + 1);
        return key;
    }
    private void addPath(List<String> path) {
        Folder cur = root;
        for (String dir : path) {
            if (!cur.dirMap.containsKey(dir)) {
                Folder child = new Folder(dir);
                cur.dirMap.put(dir, child);
                cur.dirList.add(child);
            }
            cur = cur.dirMap.get(dir);
        }
    }
    public List<List<String>> deleteDuplicateFolder(List<List<String>> paths) {
        // Build tree
        for (List<String> path : paths) {
            addPath(path);
        }
        // Build keyMap
        for (Folder f : root.dirList) {
            generateKey(f);
        }
        // System.out.println(keyMap);
        // Mark folders
        for (Folder f : root.dirList) {
            updateDeleteStatus(f);
        }
        // Build ans
        List<List<String>> ans = new ArrayList<>();
        for (List<String> path : paths) {
            if (isValid(path)) {
                ans.add(path);
            }
        }
        return ans;
    }
}
