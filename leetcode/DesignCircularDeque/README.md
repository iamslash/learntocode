# Problem

* [Design Circular Deque @ leetcode](https://leetcode.com/problems/design-circular-deque/)

# Idea

전반적인 내용은 [DesignCircularQueue @ learntocode](/leetcode/DesignCircularQueue/) 와 비슷하다.
그러나 `head` 와 `tail` 을 주의해서 초기화 해야 한다.

예를 들어서 크기가 3 인 `MyCircularDeque` 를 생각해보자. 아래와 같이 `head, tail` 을 초기화 하고 `insertFront(1), getLast()` 의 결과는 `0` 이 된다. 이것은 잘 못된 것이다.

```
     h              h
dq : 0 0 0      1 0 0
     t          t
```

따라서 아래와 같이 `head, tail` 을 초기화해야 한다.

```
         h        h
dq : 0 0 0      0 0 1
     t          t
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(1) O(N)
```
