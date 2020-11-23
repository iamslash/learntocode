# Problem

[Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/)

# Idea

바나나 더미의 모음 `P[]` 와 시간 `H` 가 주어진다. 사육사는 `H` 만큼
자리를 비울 것이다. 코코는 한번에 `P[i]` 를 한번 접근할 수 있고 `K`
만큼 먹는다고 했을 때 `H` 시간에 모두 먹을 수 있는 가장 작은 `K` 를
구하는 문제이다.

임의의 숫자 `K` 를 `1 <= piles[i] <= 10^9` 범위 에서 찾는
문제이다. 임임의 `K` 를 정하고 `P[i]` 를 모두 순회하면서 몇시간만에
먹을 수 있는지 알아보자. 그 개수를 `H` 와 비교해보고 `K` 를 다시 정할
수 있다.  충분히 binary search 를 떠올릴 수 있다.

그렇다면 임의의 `K` 에 대해 `P[i]` 를 모두 먹어치우는데 몇시간이 걸리는지
어떻게 알 수 있을까? 

`K` 로 `P[i]` 를 나눴을 때 시간이 나오도록 계산식을 만들어야 한다.
바로 `(P[i] + K - 1) / K` 와 같이 계산한다.


# Implementation

* [c++11](a.cpp)

# Complexity

```
O(PlgP) O(1)
```
