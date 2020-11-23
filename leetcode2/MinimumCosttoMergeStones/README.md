# Problem

[Minimum Cost to Merge Stones](https://leetcode.com/problems/minimum-cost-to-merge-stones/)

돌 그룹의 모임 `S[]`, 숫자 `K` 가 주어진다.  `S[]` 를 하나의 그룹이
남을 때까지 `K` 그룹씩 합친다. 만약 불가능하다면 `-1` 을 리턴한다.
합칠 때 마다 돌 개수를 더한다. 그 합이 최소가 될때 그 합을 구하라.

# Idea

예를 들어 `S = [3, 2, 4, 1], K = 2` 인 경우를 살펴보자.

```
S: [3 2] 4 1    5
S: 5 [4 1]      5
S: [5 5]       10
```
따라서 답은 `20` 이다.

`S[]` 의 길이를 `n` 이라고 하자. 마지막 그룹의 개수는 `(n-1) % (K-1) +
1` 이다??? 따라서 `(n-1) % (K-1) == 0` 이어야 `k` 개의 그룹으로 끝까지
합칠 수 있다.

cache `vector<vector<int>> C(n, vector<int>(n))` 을 선언하여 `C[i][j]`
에 `S[i..j]` 의 그룹을 합칠 때 최소 합을 저장한다.

모든 반복을 마치면 `C[0][n-1]` 이 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
```
