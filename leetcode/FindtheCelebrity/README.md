# Problem

* [Find the Celebrity](https://leetcode.com/problems/find-the-celebrity/submissions/)

# Idea

숫자 `n` 주어지면 `[0,n-1]` 의 사람들이 존재한다.  셀럽 `u` 를 찾는
문제이다. 셀럽은 하나이하 존재한다.  셀럽은 다른 사람들을 알수
없다. 그러나 다른사람들은 셀럽을 알 수 있다. `find(int u, int v)` 를
이용해서 `u` 가 `v` 를 아는지 검사하자.

셀럽후보자 `u = 0` 로 설정한다. `[1, n-1]` 을 인덱스 `i` 를 이용하여
순회한다. 순회할 때마다 `find(u, i)` 하면 `u = i` 하자.  순회가 끝나고
셀럽이 하나 있다면 `u` 는 반드시 셀럽이 된다. 그러나 셀럽이 아닐 수도
있다.

따라서 `[0, n-1]` 을 순회하면서 `u` 가 셀럽인지 검증한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
