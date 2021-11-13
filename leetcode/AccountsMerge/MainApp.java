// Copyright (C) 2021 by iamslash

import java.util.*;

// A: a, a@gmail.com, b@gmail.com
//    b, a@gmail.com, c@gmail.com

// 58ms 36.66% 43.4MB 80.76%
// disjoint set
// O(N) O(N)
class Solution {
    private String find(Map<String, String> parentMap, String s) {
        if (parentMap.get(s) == s) {
            return s;
        }
        return find(parentMap, parentMap.get(s));
    }
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        // {email: name}
        // {email: email}
        Map<String, String> ownerMap = new HashMap<>();
        Map<String, String> parentMap = new HashMap<>();
        Map<String, TreeSet<String>> mergedMap = new HashMap<>();
        // build parentMap, ownerMap
        for (List<String> acc : accounts) {
            for (int i = 1; i < acc.size(); ++i) {
                // System.out.println(acc.get(i));
                parentMap.put(acc.get(i), acc.get(i));
                ownerMap.put(acc.get(i), acc.get(0));
            }
        }
        // merge
        for (List<String> acc : accounts) {
            String parent = find(parentMap, acc.get(1));
            for (int i = 2; i < acc.size(); ++i) {
                parentMap.put(find(parentMap, acc.get(i)), parent);
            }
        }
        for (List<String> acc : accounts) {
            String parent = find(parentMap, acc.get(1));
            if (!mergedMap.containsKey(parent)) {
                mergedMap.put(parent, new TreeSet<>());
            }
            for (int i = 1; i < acc.size(); ++i) {
                mergedMap.get(parent).add(acc.get(i));
            }
        }
        List<List<String>> ans = new ArrayList<>();
        for (String parent : mergedMap.keySet()) {
            List<String> emails = new ArrayList<>(mergedMap.get(parent));
            emails.add(0, ownerMap.get(parent));
            ans.add(emails);
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
