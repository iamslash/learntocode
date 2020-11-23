# Problem

[Image Overlap](https://leetcode.com/problems/image-overlap/)

# Idea

`0` 혹은 `1` 의 값으로만 채워진 매트릭스 `A[][], B[][]` 가
주어진다. `A[][]` 를 상하좌우로 이동했을 때 `B[][]` 와 가장 많이
겹치는 `1` 의 개수를 구하는 문제이다.

`vector<pair<int, int> C` 를 선언하고 인덱스 `y, x` 를 이용하여
순회한다. `A[y][x] == 1` 일때 `{y,x}` 을 `C` 에 삽입하자.

`vector<pair<int, int> D` 를 선언하고 인덱스 `y, x` 를 이용하여
순회한다. `B[y][x] == 1` 일때 `{y,x}` 을 `D` 에 삽입하자.

`unordered_map<string, int> cnts` 를 선언하고 모든 `C[], D[]` 에 대해
`cnts[C[i].first - D[j].first + " " + C[i].second - D[j].second]++` 를
수행한다. 모양이 같은 녀석들의 개수는 `cnts` 에서 같은 key 의 val
이다. `cnts` 가 모두 채워지면 val 이 가장 큰 것이 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2) O(N)
```
