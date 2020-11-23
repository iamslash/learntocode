# Problem

[Bag of Tokens](https://leetcode.com/problems/bag-of-tokens/submissions/)

# Idea

토큰의 모음 `token[]` 와 파워 `power` 가 주어진다.  `token[i] <=
power` 이면 `token[i]` 를 하나 소모하고 `power -= token[i], point +=
1` 할 수 있다. 또한 `point > 0` 이면 `token[i]` 를 하나 소모하고
`power += token[i], point -= 1` 할 수 있다. 가장 많은 `point` 를
얻을 수 있을 때 그 `point` 를 구하는 문제이다.

무언가 최대를 구하는 문제이다. greedy 로 해결할 만 하다.  `token[]` 를
모두 소모해서 `point` 를 최대로 해야 한다.  `point` 를 최대로 하기
위해서는 `power` 를 최대로 유지해야 한다.

`token[i] <= power` 인 경우는 `power -= token[i]` 해야 하기 때문에
최소의 `token[i]` 를 선택해야 한다.  `point > 0` 일 때는 `power +=
token[i]` 해야 하기 때문에 최대의 `token[i]` 를 선택해야 한다.
`token[]` 을 오름차순으로 정렬하고 양끝을 인덱스 `i, j` 를 이용하여
가리키면 최소 혹은 최대 토큰을 얻을 수 있다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(1)
```
