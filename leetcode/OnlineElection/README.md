# Problem

[Online Election](https://leetcode.com/problems/online-election/)

# Idea

`i-th` 표는 `P[i]` 의 사람에게 `T[i]` 의 시간에 할당된다.  시간을 주고
그 때 가장 앞선 사람을 구하는 문제이다.

예를 들어 `P = 0 1 1 0 0 1 0, T = 0 5 10 15 20 25 30` 의 경우를
살펴보자. 다음과 같이 시간이 흐를 때 어떤 사람이 앞서고 있는지 `L[]`
에 저장할 수 있다.

```
T: 0 5 10 15 20 25 30 
P: 0 1  1  0  0  1  0
L: 0 1  1  0  0  1  0
```

`{T[i] : L[i]}` 를 `map<int, int> m_leads` 에 저장한다면
`m_leads.upper_bound(t)` 를 이용하여 특정 시간에 앞서고 있는
사람을 쉽게 구할 수 있다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
a: O(lgN) O(N)
```
