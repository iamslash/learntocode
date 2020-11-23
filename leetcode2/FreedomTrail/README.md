# Problem

[Freedom Trail](https://leetcode.com/problems/freedom-trail/)

문자열 `ring` 과 `key` 가 주어진다. `ring` 은 양끝이 이어진 원형을
이루고 있다. 그리고 가장 북쪽에 해당하는 문자가 하나 있다. `ring` 을
왼쪽 혹은 오른쪽으로 한칸씩 돌릴 수 있다. 이제 `ring[0]` 를 가장
북쪽에 두고 왼쪽 혹은 오른쪽으로 돌려가며 `key` 에 해당하는 문자들을
차례대로 찾는다. 문자를 찾을 때 마다 기본 비용 1 이 소모
된다. 최소한의 회전 횟수를 구하라.

# Idea

예를 들어 `ring = "godding", key = "gd"` 인 경우를 살펴보자.

```
for 'g' of "gd" : 1

  cost of clock-wise: 0
  .                . 
  g o d d i n g    g o d d i n g

  cost of count-clock-wise: 0
  .                . 
  g o d d i n g    g o d d i n g

for 'd' of "gd" : 3

  cost of clock-wise: 2
  .                    . 
  g o d d i n g    g o d d i n g

  cost of count-clock-wise: 4
  .                      . 
  g o d d i n g    g o d d i n g

the answer is 4
```

dynamic programming 으로 해결할 만 하다.

`unordered_map<string, int> C` 를 선언하여 `{ring + i : minimum cost}`
를 저장한다.  hash key 는 `ring` 문자열에 이번에 방문하는 `key` 의
인덱스를 더한 문자열이다.

다음과 같이 부분 문제 `dfs` 를 선언하고 재귀적으로 해결한다.

```c
int dfs(C, ring, key, i)

return: minimum cost
     C: {ring + i : minimum cost}
   key: key string
     i: index of key
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(RK) O(RK)
```
