/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <mutex>
#include <condition_variable>
#include <functional>

// 400ms 49.10% 11.1MB 100.00%
class H2O {
 private:
  std::mutex m_mu;
  std::condition_variable m_cv;
  int m_i = 1;
 public:
  H2O() {
        
  }

  void hydrogen(std::function<void()> releaseHydrogen) {
    std::unique_lock<std::mutex> ulock(m_mu);
    m_cv.wait(ulock, [this](){ return m_i % 3 != 0; }); 
    releaseHydrogen();
    ++m_i;
    if (m_i % 3 == 0) {
      ulock.unlock();
      m_cv.notify_all();
    }
  }

  void oxygen(std::function<void()> releaseOxygen) {
    std::unique_lock<std::mutex> ulock(m_mu);
    m_cv.wait(ulock, [this]{ return m_i % 3 == 0; }); 
    releaseOxygen();
    ++m_i;
    ulock.unlock();
    m_cv.notify_all();
  }
};

int main() {
  return 0;
}
