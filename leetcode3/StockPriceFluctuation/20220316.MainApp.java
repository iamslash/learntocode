// Copyright (C) 2022 by iamslash

import java.util.*;

// 217ms 44.48% 173.8MB 20.83%
// hash map
//  update: O(NlgN) O(N)
// current: O(1) O(N)
// maximum: O(1) O(N)
// minimum: O(1) O(N)
class StockPrice {
    Map<Integer, Integer> tsPriceMap = new HashMap<>();
    int lastTs = -1;
    SortedMap<Integer, Set<Integer>> priceTssMap = new TreeMap<>((a, b) -> a - b);
    public StockPrice() {
        
    }
    public void update(int ts, int price) {
        lastTs = Math.max(lastTs, ts);
        // hit
        if (tsPriceMap.containsKey(ts)) {
            int prevPrice = tsPriceMap.get(ts);
            priceTssMap.get(prevPrice).remove(ts);
            if (priceTssMap.get(prevPrice).isEmpty()) {
                priceTssMap.remove(prevPrice);
            }
        }
        // save
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

public class MainApp {
  public static void main(String[] args) {
  }
}
