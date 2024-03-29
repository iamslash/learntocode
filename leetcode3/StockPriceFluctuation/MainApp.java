// Copyright (C) 2023 by iamslash

// 163ms 39.47% 95.9MB 38.80%
// hash map
// update: O(NlgN)
// current: O(1)
// maximum: O(1)
// minimum: O(1)
import java.util.*;
class StockPrice {
    int lastTs = -1;
    Map<Integer, Integer> tsPriceMap = new HashMap<>();
    SortedMap<Integer, Set<Integer>> priceTssMap = new TreeMap<>((a, b) -> a - b);

    public void update(int ts, int price) {
        lastTs = Math.max(lastTs, ts);
        // Hit
        if (tsPriceMap.containsKey(ts)) {
            int prevPrice = tsPriceMap.get(ts);
            priceTssMap.get(prevPrice).remove(ts);
            if (priceTssMap.get(prevPrice).isEmpty()) {
                priceTssMap.remove(prevPrice);
            }
        }
        // Save
        tsPriceMap.put(ts, price);
        priceTssMap.putIfAbsent(price, new HashSet<>());
        priceTssMap.get(price).add(ts);
    }
    
    public int current() {
        return tsPriceMap.get(lastTs);
    }
    
    public int maximum() {
        return priceTssMap.lastKey();
    }
    
    public int minimum() {
        return priceTssMap.firstKey();
    }
}
