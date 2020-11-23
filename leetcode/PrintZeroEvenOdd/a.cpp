/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <functional>
#include <atomic>
#include <thread>
#include <condition_variable>
#include <queue>

// // 64ms 27.53% 9.1MB 100.00%
// class ZeroEvenOdd {
//  private:
//   int n;
//   std::mutex m_mu;
//   std::condition_variable m_cv;
//   bool m_print_zero = true;
//   int  m_num = 1;
//  public:
//   ZeroEvenOdd(int n) {
//     this->n = n;
//   }

//   // printNumber(x) outputs "x", where x is an integer.
//   void zero(std::function<void(int)> printNumber) {
//     while (m_num <= n) {
//       std::unique_lock<std::mutex> ulock(m_mu);
//       m_cv.wait(ulock, [this]{ return m_print_zero; });
//       if (m_num <= n)
//         printNumber(0);
//       m_print_zero = false;
//       ulock.unlock();
//       m_cv.notify_all();
//     }
//   }

//   void even(std::function<void(int)> printNumber) {
//     while (m_num <= n) {
//       std::unique_lock<std::mutex> ulock(m_mu);
//       m_cv.wait(ulock, [this]{ return !m_print_zero && m_num % 2 == 0; });
//       if (m_num <= n) {
//         printNumber(m_num);
//         ++m_num;
//         m_print_zero = true;
//       }
//       ulock.unlock();
//       m_cv.notify_all();
//     }
//   }

//   void odd(std::function<void(int)> printNumber) {
//     while (m_num <= n) {
//       std::unique_lock<std::mutex> ulock(m_mu);
//       m_cv.wait(ulock, [this]{ return !m_print_zero && m_num % 2 != 0; });
//       if (m_num <= n) {
//         printNumber(m_num);
//         ++m_num;
//         m_print_zero = true;
//       }
//       ulock.unlock();
//       m_cv.notify_all();
//     }
//   }
// };

// 68ms 19.03% 9.2MB 100.00%
class ZeroEvenOdd {
 private:
  std::condition_variable m_cv;
  std::mutex m_mu;
  std::queue<int> m_q;
 public:
  ZeroEvenOdd(int n) {
    for (int i = 1; i <= n; ++i) {
      m_q.push(0);
      m_q.push(i);
    }
  }
  void print(std::function<void(int)> printNumber,
             std::function<bool(int)> cond) {
    std::unique_lock<std::mutex> ulock(m_mu);
    for (;;) {
      m_cv.wait(
          ulock,
          [this, &cond]{ return m_q.empty() || cond(m_q.front()); });
      if (m_q.empty())
        break;
      printNumber(m_q.front()); m_q.pop();
      m_cv.notify_all();
    }
  }

  void zero(std::function<void(int)> printNumber) {
    print(printNumber, [](int v){ return v == 0; });
  }
  void odd(std::function<void(int)> printNumber) {
    print(printNumber, [](int v){ return (v%2) == 1; });
  }
  void even(std::function<void(int)> printNumber) {
    print(printNumber, [](int v){ return (v%2) == 0 && v != 0; });
  }
};

int main() {
  return 0;
}
