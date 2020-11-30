# Problem

[Design Front Middle Back Queue](https://leetcode.com/problems/design-front-middle-back-queue/)

# Idea

예를 들어 `data = [1, 2, 3, 4, 5]` 인 경우 `6` 을 가운데 값을 삽입해
보자. `data = [1, 2, 6, 3, 4, 5]` 가 된다.

또한 `data = [1, 2, 3, 4, 5, 6]` 인 경우 가운데 값을 제거해 보자.
`data = [1, 2, 4, 5, 6]` 이 된다.

중간의 값을 어떻게 처리하느냐가 중요하다. `deque<int> a, b` 를
선언하여 데이터의 앞부분을 `a` 에 저장하고 뒷부분을 `b` 에 저장해
보자. 그렇다면 중간의 원소는 `a.back()` 혹은 `b.font()` 가 된다.

이제 값이 삽입 혹은 삭제 될때 `a, b` 의 개수를 적당히 균형을 맞추면
된다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(1) O(N)
```
