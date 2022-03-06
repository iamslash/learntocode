// Copyright (C) 2022 by iamslash

import java.util.*;

// 65ms 88.65% 130.6MB 83.67%
// hash map
// get: O(1) O(N)
// put: O(1) O(N)
class LFUCache {
    Map<Integer, Integer> valMap;  // {key, val}
    Map<Integer, Integer> freqMap; // {key, freq}
    Map<Integer, Set<Integer>> freq2keysMap; // {freq, {key, ...}}
    int cap;
    int minFreq = -1;
    public LFUCache(int capacity) {
        cap = capacity;
        valMap = new HashMap<>();
        freqMap = new HashMap<>();
        freq2keysMap = new HashMap<>();
        freq2keysMap.put(1, new LinkedHashSet<>());
    }
    
    public int get(int key) {
        if (!valMap.containsKey(key)) {
            return -1;
        }
        int freq = freqMap.get(key);
        freqMap.put(key, freq+1);
        freq2keysMap.get(freq).remove(key);
        if (freq == minFreq && freq2keysMap.get(freq).size() == 0) {
            minFreq++;
        }
        if (!freq2keysMap.containsKey(freq+1)) {
            freq2keysMap.put(freq+1, new LinkedHashSet<>());
        }
        freq2keysMap.get(freq+1).add(key);
        return valMap.get(key);
    }
    
    public void put(int key, int val) {
        if (cap <= 0) {
            return;
        }
        if (valMap.containsKey(key)) {
            valMap.put(key, val);
            get(key);
            return;
        }
        if (valMap.size() >= cap) {
            int keyToEvict = freq2keysMap.get(minFreq).iterator().next();
            freq2keysMap.get(minFreq).remove(keyToEvict);
            valMap.remove(keyToEvict);
        }
        valMap.put(key, val);
        freqMap.put(key, 1);
        minFreq = 1;
        freq2keysMap.get(1).add(key);
    }
}

// 152ms 33.42% 186.6MB 39.96%
// hash map
// get: O(1) O(N)
// put: O(1) O(N)
class LFUCache {
    Map<Integer, int[]> valFreqMap;  // {key, [val, fre]}
    Map<Integer, Set<Integer>> freq2keysMap; // {freq, {key, ...}}
    int cap;
    int minFreq = -1;
    public LFUCache(int capacity) {
        cap = capacity;
        valFreqMap = new HashMap<>();
        freq2keysMap = new HashMap<>();
        freq2keysMap.put(1, new LinkedHashSet<>());
    }
    
    public int get(int key) {
        // miss
        if (!valFreqMap.containsKey(key)) {
            return -1;
        }
        // hit
        int[] item = valFreqMap.get(key);
        int val = item[0], freq = item[1];
        item[1] = freq+1;
        freq2keysMap.get(freq).remove(key);
        if (freq == minFreq && freq2keysMap.get(freq).size() == 0) {
            minFreq++;
        }
        if (!freq2keysMap.containsKey(freq+1)) {
            freq2keysMap.put(freq+1, new LinkedHashSet<>());
        }
        freq2keysMap.get(freq+1).add(key);
        return val;
    }
    
    public void put(int key, int val) {
        if (cap <= 0) {
            return;
        }
        // hit
        if (valFreqMap.containsKey(key)) {
            int[] item = valFreqMap.get(key);
            item[0] = val;
            valFreqMap.put(key, item);
            get(key);
            return;
        }
        // evict
        if (valFreqMap.size() >= cap) {
            int keyToEvict = freq2keysMap.get(minFreq).iterator().next();
            freq2keysMap.get(minFreq).remove(keyToEvict);
            valFreqMap.remove(keyToEvict);
        }
        // save
        valFreqMap.put(key, new int[]{val, 1});
        minFreq = 1;
        freq2keysMap.get(1).add(key);
    }
}
