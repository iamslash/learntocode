/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <mutex>
#include <condition_variable>
#include <queue>

// 92ms 91.67% 11.3MB 100.00%
class BoundedBlockingQueue {
 private:
  int m_cap;
  std::mutex m_mutex;
  std::condition_variable m_cv;
  std::queue<int> q;
 public:
  BoundedBlockingQueue(int cap) {
    m_cap = cap;
  }

  void enqueue(int a) {
    std::unique_lock<std::mutex> ulck(m_mutex);
    while (q.size() >= m_cap)
      m_cv.wait(ulck);
    q.push(a);
    m_cv.notify_all();
  }

  int dequeue() {
    std::unique_lock<std::mutex> ulck(m_mutex);
    while (q.empty())
      m_cv.wait(ulck);
    int f = q.front(); q.pop();
    m_cv.notify_all();
    return f;
  }
    
  int size() {
    std::unique_lock<std::mutex> ulck(m_mutex);
    return q.size();
  }
};

int main() {
  return 0;
}
