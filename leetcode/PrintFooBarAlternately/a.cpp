/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <mutex>
#include <functional>
#include <atomic>
#include <thread>

// // 304ms 87.35% 10.5MB 100.00%
// class FooBar {
//  private:
//   int n;
//   std::mutex m_mufoo, m_mubar;

//  public:
//   FooBar(int n) {
//     this->n = n;
//     m_mubar.lock();
//   }

//   void foo(std::function<void()> printFoo) {
        
//     for (int i = 0; i < n; i++) {
//       m_mufoo.lock();      
//       printFoo();
//       m_mubar.unlock();
//     }
//   }

//   void bar(std::function<void()> printBar) {
        
//     for (int i = 0; i < n; i++) {
//       m_mubar.lock();           
//       printBar();
//       m_mufoo.unlock();
//     }
//   }
// };

// 316ms 82.74% 10.5MB 100.00%
class FooBar {
 private:
  int n;
  std::atomic_bool m_b;

 public:
  FooBar(int n) {
    this->n = n;
    m_b = false;
  }

  void foo(std::function<void()> printFoo) {
        
    for (int i = 0; i < n; i++) {
      while (m_b)
        std::this_thread::yield();
      printFoo();
      m_b = !m_b;
    }
  }

  void bar(std::function<void()> printBar) {
        
    for (int i = 0; i < n; i++) {
      while (!m_b)
        std::this_thread::yield();      
      printBar();
      m_b = !m_b;
    }
  }
};


int main() {
  return 0;
}
