// Copyright (C) 2024 by iamslash

import java.util.*;

// 111ms 63.80% 46.1MB 27.30%
// hash map
// O(n * m^2 log m^2) O(n * m^2)
class Solution {
    public String[] shortestSubstrings(String[] arr) {
        int n = arr.length;
        Map<String, Integer> freqMap = new HashMap<>();

        // Corrected loop to include last character in substring
        for (int i = 0; i < n; ++i) {
            String s = arr[i];
            int m = s.length();
            Set<String> strSet = new HashSet<>();
            for (int j = 0; j < m; j++) {
                for (int k = j + 1; k <= m; ++k) { 
                    strSet.add(s.substring(j, k));
                }
            }
            for (String ss : strSet) {
                freqMap.put(ss, freqMap.getOrDefault(ss, 0) + 1);
            }
        }

        // Processing to find and set the shortest unique substring
        for (int i = 0; i < n; ++i) {
            String s = arr[i];
            int m = s.length();
            List<String> strList = new ArrayList<>();
            for (int j = 0; j < m; ++j) {
                for (int k = j + 1; k <= m; ++k) { 
                    String ss = s.substring(j, k);
                    if (freqMap.get(ss) == 1) {
                        strList.add(ss);
                    }
                }
            }
            if (strList.isEmpty()) {
                arr[i] = "";
            } else {
                Collections.sort(strList);
                String minStr = strList.get(0);
                for (int j = 1; j < strList.size(); ++j) {
                    String ss = strList.get(j);
                    if (ss.length() < minStr.length()) {
                        minStr = ss;
                    }
                }
                arr[i] = minStr;

            }
        }

        return arr;
    }
}

// 12ms 100.00% 45.4MB 65.39%
// trie
// O(n*m^3) O(n*m^2)
class TrieNode {
    TrieNode[] next;
    int count;

    public TrieNode() {
        next = new TrieNode[26];
        count = 0;
    }
}
class Solution {
    public String[] shortestSubstrings(String[] arr) {
        int n = arr.length;
        String[] ans = new String[n];
        TrieNode root = new TrieNode();
        
        // Building the Trie with character frequencies
        for (String s : arr) {
            char[] chars = s.toCharArray();
            for (int i = 0; i < s.length(); i++) {
                TrieNode u = root;
                for (int j = i; j < s.length(); j++) {
                    if (u.next[chars[j] - 'a'] == null) {
                        u.next[chars[j] - 'a'] = new TrieNode();
                    }
                    u = u.next[chars[j] - 'a'];
                    u.count++;
                }
            }
        }
        
        // Searching for shortest unique substrings
        for (int idx = 0; idx < n; idx++) {
            char[] chars = arr[idx].toCharArray();
            
            // Decrementing counts to find unique substring
            for (int i = 0; i < chars.length; i++) {
                TrieNode u = root;
                for (int j = i; j < chars.length; j++) {
                    u.next[chars[j] - 'a'].count--;
                    u = u.next[chars[j] - 'a'];
                }
            }
            
            // Identifying the shortest unique substring
            for (int i = 0; i < chars.length; i++) {
                TrieNode u = root;
                for (int j = i; j < chars.length; j++) {
                    if (u.next[chars[j] - 'a'].count == 0) {
                        String candidate = arr[idx].substring(i, j + 1);
                        if (ans[idx] == null || ans[idx].length() > candidate.length() || 
                            (ans[idx].length() == candidate.length() && ans[idx].compareTo(candidate) > 0)) {
                            ans[idx] = candidate;
                        }
                        break; // Found the unique substring, move to next starting position
                    }
                    u = u.next[chars[j] - 'a'];
                }
            }
            
            // Resetting the count for the next search
            for (int i = 0; i < chars.length; i++) {
                TrieNode u = root;
                for (int j = i; j < chars.length; j++) {
                    u.next[chars[j] - 'a'].count++;
                    u = u.next[chars[j] - 'a'];
                }
            }
            
            // Handling case where no unique substring was found
            if (ans[idx] == null)
                ans[idx] = "";
        }
        return ans;
    }
}

