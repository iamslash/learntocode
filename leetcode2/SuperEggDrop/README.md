# Problem

[Super Egg Drop](https://leetcode.com/problems/super-egg-drop/)

숫자 `K, N` 이 주어진다. 달걀이 `K` 개 있고 계단이 `N` 개 있다. 이때
`0 <= F <= N` 인 `F` 를 찾아보자. `F` 보다 큰 계단에 달걀을 떨어뜨리면
깨진다. `F` 를 찾기위해 최소한으로 움직여 보자. 그때 최소한의 움직임수를
구하라.

# Idea

iterative dynamic programming 으로 해결할 만 하다.

`vector<int> C(K+1)` 을 선언하여 `K` 개의 달걀로 `F` 를 찾을 수 있는
최소 움직임수를 저장한다.

`Q(k, s)` 를 `k` 개의 달걀과 `s` 개의 계단에서 최소 움직임수라고
해보자. 

* 1 개의 달걀을 꺼내어 `s` 번째 계단에 떨어뜨려 깨지면 `k-1`
개의 달걀과 `s-1` 개의 계단에서 다시 탐색할 수 있다. 즉, `Q(k-1, s-1)`
과 같다. 
* 1 개의 달걀을 꺼내어 `s` 번째 계단에 떨으뜨려 깨지지 않으면
`k` 개의 달걀과 `s-1` 개의 계단에서 다시 탐색할 수 있다.즉, `Q(k,
s-1)` 과 같다.
* 따라서 `Q(k, s) = 1 + Q(k, s-1) + Q(k-1, s-1)` 이다.

어렵다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NK) O(K)
```
