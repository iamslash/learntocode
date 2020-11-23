/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>

// 48ms 93.15% 22.5MB 29.93%
class Twitter {
 private:
  int m_time = 0;
  // {userid : followers}
  std::unordered_map<int, std::unordered_set<int>> m_follow;
  // {{userid : ({time : tweetid}, ...)}, ...}
  std::unordered_map<int, std::vector<std::pair<int, int>>> m_tweets; 
 public:
  Twitter() {}
    
  void postTweet(int u, int t) {
    m_tweets[u].emplace_back(m_time++, t);
  }
    
  std::vector<int> getNewsFeed(int u) {

    std::priority_queue<std::pair<int, int>> pq;
    for (auto it = m_tweets[u].begin(); it != m_tweets[u].end(); ++it)
      pq.push(*it);
    for (auto it = m_follow[u].begin(); it != m_follow[u].end(); ++it) {
      for (auto jt = m_tweets[*it].begin(); jt != m_tweets[*it].end(); ++jt) {
        pq.push(*jt);
      }
    }
    
    std::vector<int> rslt;
    while (pq.size() && rslt.size() < 10) {
      auto pr = pq.top(); pq.pop();
      rslt.push_back(pr.second);
    }
    return rslt;
  }
  
  void follow(int f, int u) {
    if (f == u)
      return;
    m_follow[f].insert(u);
  }
    
  void unfollow(int f, int u) {
    m_follow[f].erase(u);
  }
};

void printfeed(std::vector<int> feeds) {
  for (int f : feeds)
    printf("%d ", f);
  printf("\n");
}

int main() {
  Twitter obj;

  obj.postTweet(1, 1);
  auto fd = obj.getNewsFeed(1);
  printfeed(fd);
  
  obj.follow(2, 1);
  obj.postTweet(1, 2);
  fd = obj.getNewsFeed(2);
  printfeed(fd);

  obj.unfollow(2, 1);
  fd = obj.getNewsFeed(2);
  printfeed(fd);

  return 0;
}
