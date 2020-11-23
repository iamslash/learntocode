# Problem

[Find the Shortest Superstring](https://leetcode.com/problems/find-the-shortest-superstring/)

# Idea

문자열의 모음 `A[]` 가 주어진다. 모든 `A[i]` 들이 substring 이 되는
최소길이의 문자열을 구하는 문제이다.

예를 들어 `A[i] = abcd` 와 `A[j] = bcde` 를 substring 으로 하는
최소길이의 문자열은 `abcde` 이다. 겹치는 구간이 최대인 문자열을 구하면
된다.

그리고 `G[][]` 를 선언하여 `A[i]` 에서 `A[j]` 까지 겹치치 않는 구간의
길이를 `G[i][j]` 라고 하자. 즉, `G[i][j]` 가 작으면 작을 수록 겹치는
구간이 최대인 문자열을 만들어 낼 수 있다.

이제 `G[i][a] + G[b][c] + ... + G[y][z] + G[z][j]` 가 최소인 연결을
찾아내면 답이 된다. 이것은 [TSP](/algospot/TSP), [TSP2](/algospot/TSP2/README.md) 와
같다. dynamic programming 으로 풀어낼 수 있다.

`C[s][j]` 를 선언한다. `s` 은 방문한 node 들을 bitmask 로 저장한
것이다. `s = 0101` 이면 `0, 2` node 를 방문한 상황에서 `j` node 까지
거리중 최소값을 저장한다.

`P[s][j]` 를 선언한다. 마찬가지로 `s` 은 방문한 node 들을 bitmask 로
저장한 것이다. `s = 0101` 이면 `0, 2` node 를 방문한 상황에서 `j` node
까지 경로중 최소에 해당하는 node 를 저장한다.

`C[][], P[][]` 를 모두 채우면 최소 경로를 reconstruct 할 수 있다.

# Implementation

* [c++11](a.cpp)
* [java8](Solution.java)

# Complexity

```
O(n^2 * 2^n) O(N^2)
```
