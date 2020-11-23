# Problem

Lifo-in-First-out Data Structure 를 design 하고 다음을 구현하라.

```c
void push(int x)
bool isEmpty() 
int top() 
bool pop() 
```

# References

* [Last-in-first-out Data Structuren @ leetcode](https://leetcode.com/explore/learn/card/queue-stack/230/usage-stack/1369/)

# Idea

`vector<int> m_data` 를 선언하고 구혀한다.

# Implementation

* [c++11](a.cpp)
* [py3](a.py)

# Complexity

```
   push: O(1)
    pop: O(1)
    top: O(1)
isEmpty: O(1)
```
