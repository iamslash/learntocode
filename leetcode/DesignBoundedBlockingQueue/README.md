# Problem

[Design Bounded Blocking Queue](https://leetcode.com/problems/design-bounded-blocking-queue/)

# Idea

thread safe queue 를 구현하는 문제이다. 다음과 같은 함수들을 구현한다.

```cpp
class BoundedBlockingQueue {
 public:
  BoundedBlockingQueue(int capacity) {
  }
  void enqueue(int element) {
  }
  int dequeue() {
  }
  int size() {
  }
};
```

먼저 queue 를 구현하는 것이므로 `queue<int> m_q` 를 선언한다. 그리고
생성자에서 `capacity` 를 설정해야 하므로 `int m_cap` 를 선언한다.

`enqueue` 에서 `m_q.size() >= m_cap` 인 동안 대기해야 한다. 따라서
`condition_variable m_cv` 를 선언하여 이용한다. `condition_variable`
를 사용하기 위해서는 `mutex m_mutex` 를 선언해야 한다.

`deque` 에서 `m_q.empty()` 인 동안 대기해야 한다. `m_cv, m_mutex` 
를 이용한다.

`unique_lock<mutex> ulck(m_mutex)` 를 선언하면 편리하게 락을 핸들링할
수 있다.

# Implementation

* [c++11](a.cpp)

