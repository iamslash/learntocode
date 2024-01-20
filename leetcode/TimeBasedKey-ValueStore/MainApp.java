// Copyright (C) 2024 by iamslash

import java.util.*;

// 158ms 25.40% 120.1MB 27.87%
// hash map
// O(NlgN) O(N)
class TimeMap {

    private Map<String, TreeMap<Integer, String>> map = new HashMap<>();

    public TimeMap() {
    }
    
    public void set(String key, String val, int ts) {
        if (!map.containsKey(key)) {
            map.put(key, new TreeMap<>());
        }
        map.get(key).put(ts, val);
    }
    
    public String get(String key, int ts) {
        if (!map.containsKey(key)) {
            return "";
        }
        TreeMap<Integer, String> tsMap = map.get(key);
        Integer floor = tsMap.floorKey(ts);
        if (floor == null) {
            return "";
        }
        return tsMap.get(floor);
    }
}
