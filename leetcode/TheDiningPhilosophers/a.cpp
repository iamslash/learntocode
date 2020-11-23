/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <mutex>
#include <functional>




// 124ms 96.96% 11.2MB 100.00%
// mutex
// oddth philosopher has to pick left fork first
// eventh philosopher has to pick right fork first
class DiningPhilosophers {
 private:
  std::vector<std::mutex> locks = std::vector<std::mutex>(5);
 public:
  DiningPhilosophers() {
  }

  void wantsToEat(int philosopher,
                  std::function<void()> pickLeftFork,
                  std::function<void()> pickRightFork,
                  std::function<void()> eat,
                  std::function<void()> putLeftFork,
                  std::function<void()> putRightFork) {
    int n = locks.size();
    int l = philosopher % n;
    int r = (philosopher+1) % n;
    // if (philosopher % n == 1) {
    if (philosopher & 1) {
      locks[r].lock();
      locks[l].lock();
      pickRightFork();
      pickLeftFork();
      eat();
      putLeftFork();
      putRightFork();
      locks[l].unlock();
      locks[r].unlock();          
    } else {
      locks[l].lock();
      locks[r].lock();
      pickRightFork();
      pickLeftFork();
      eat();
      putLeftFork();
      putRightFork();
      locks[r].unlock(); 
      locks[l].unlock();
    }    
  }
};

int main() {
  return 0;
}
