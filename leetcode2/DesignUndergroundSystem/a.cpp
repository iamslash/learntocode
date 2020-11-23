/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <unordered_map>
#include <string>

using namespace std;

// 308ms 69.41% 59.1MB 42.10%
// hash map
// checkIn: O(1)
// checkOut: O(1)
// getAverageTimeO(1)
class UndergroundSystem {
 private:
  unordered_map<int, pair<string, int>> checkinMap; // {user_id: {startStation, time}}
  unordered_map<string, pair<int, int>> statMap; // {startStation_endStation: {duration, count}}
 public:
  UndergroundSystem() {
        
  }
    
  void checkIn(int id, string stationName, int t) {
    checkinMap[id] = {stationName, t};
  }
    
  void checkOut(int id, string stationName, int t) {
    auto &pr = checkinMap[id];
    string path = pr.first + "_" + stationName;
    statMap[path].first += t - pr.second;
    statMap[path].second += 1;
  }
    
  double getAverageTime(string startStation, string endStation) {
    auto &pr = statMap[startStation + "_" + endStation];
    return (double)pr.first / pr.second;
  }
};
