/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>

// 32ms 89.74% 9.2MB 100.00%
// using condition_variable
class FizzBuzz {
 private:
  int n;
  int i;
  std::mutex mtx;
  std::condition_variable cv;

 public:
  FizzBuzz(int n) {
    this->n = n;
    i = 1;
  }

  void run(std::function<bool(int)> test, std::function<void(int)> print) {
    while (true) {
      std::unique_lock<std::mutex> lock(mtx);
      cv.wait(lock, [&]{ return i > n || test(i); });
      if (i > n)
        break;
      print(i++);
      lock.unlock();
      cv.notify_all();
    }
  }

  // printFizz() outputs "fizz".
  void fizz(std::function<void()> printFizz) {
    run([](int i){ return i % 3 == 0 && i % 5 != 0; },
        [&](int i){ printFizz(); });
  }

  // printBuzz() outputs "buzz".
  void buzz(std::function<void()> printBuzz) {
    run([](int i){ return i % 5 == 0 && i % 3 != 0; },
        [&](int i){ printBuzz(); });
  }

  // printFizzBuzz() outputs "fizzbuzz".
  void fizzbuzz(std::function<void()> printFizzBuzz) {
    run([](int i){ return i % 5 == 0 && i % 3 == 0; },
        [&](int i){ printFizzBuzz(); });        
  }

  // printNumber(x) outputs "x", where x is an integer.
  void number(std::function<void(int)> printNumber) {
    run([](int i){ return i % 5 != 0 && i % 3 != 0; },
        printNumber);    
  }
};

int main() {
  return 0;
}
