/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <unordered_map>
#include <list>

using namespace std;

// 204ms 78.38%
// reverse indexing
// O(1) O(N)
class LFUCache {
 private:
  int cap;
  int size;
  int minFreq;
  unordered_map<int, pair<int, int>> key2valfreq; // {key: {value, freq}}
  unordered_map<int, list<int>::iterator> key2iter; // {key: iterator}
  unordered_map<int, list<int>> freq2keys;
 public:
  LFUCache(int capacity) {
    cap = capacity;
    size = 0;
  }
  
  int get(int key) {
    if (key2valfreq.count(key) == 0)
      return -1;
    auto& freq = key2valfreq[key].second; 
    freq2keys[freq].erase(key2iter[key]);
    freq++;
    freq2keys[freq].push_back(key);
    key2iter[key] = prev(freq2keys[freq].end());

    if (freq2keys[minFreq].size() == 0)
      minFreq++;
    return key2valfreq[key].first;
  }
    
  void put(int key, int val) {
    if (cap <= 0)
      return;
    int oldVal = get(key);
    if (oldVal != -1) {
      key2valfreq[key].first = val;
      return;
    }
    if (size >= cap) {
      auto& minFreqList = freq2keys[minFreq];
      int minFreqKey = minFreqList.front();
      key2valfreq.erase(minFreqKey);
      key2iter.erase(minFreqKey);
      minFreqList.pop_front();
      size--;
    }
    key2valfreq[key] = {val, 1};
    freq2keys[1].push_back(key);
    key2iter[key] = prev(freq2keys[1].end());
    minFreq = 1;
    size++;
  }
};
