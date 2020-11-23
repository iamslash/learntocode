# Problem

First-in-First-out Data Structure 를 design 하고 
다음을 구현하라.

```c
bool enQueue(int a)
bool deQueue()
int front()
bool isEmpty()
```

# References

* [Queue - Implementation @
  leetcode](https://leetcode.com/explore/learn/card/queue-stack/228/first-in-first-out-data-structure/1366/)

# Idea

`vector<int> m_data, int m_pos` 를 선언하고 구혀한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
enQueue: O(1)
deQueue: O(1)
  front: O(1)
isEmpty: O(1)
```
