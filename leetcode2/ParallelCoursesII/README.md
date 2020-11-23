# Problem

[Parallel Courses II](https://leetcode.com/problems/parallel-courses-ii/)

숫자 `n, k`, 간선의 모음 `E[][]` 이 주어진다. `n` 개의 과목이 있고
한개의 비용으로 `k` 개를 수강할 수 있다. `E[i][0]` 은 `E[i][1]` 의
선수 과목이다. 모든 과목을 수강하기 위한 비용을 구하라.

# Idea

예를 들어 `n = 4, dependencies = [[2,1],[3,1],[1,4]], k = 2` 의 경우를
살펴보자.

```
2 - 1 - 4
  /
3

2,3 1 4
```

따라서 답은 3 이다. 

모든 경우의 수를 시도해본다. 그리고 memoization 으로 최적화
한다. dynamic programming 으로 해결할 만 하다. 특히 [bit mask
set](/fundamentals/bitmask/bitmaskset/README.md) 를 참고하면 bit
manipulation 을 수월하게 할 수 있다.

`int[] parent = new int [n]` 를 선언하여 `parent[u]` 에 자식과목 `u`
의 부모과목 bit mask 를 저장한다. `E[][]` 를 순회하면서 `parent[]` 를
채운다.

`int[] C = new int[1 << n]` 을 선언하여 `C[bm]` 에 수강한 과목의 bit
mask bm 의 최소 비용을 저장한다. 0 개의 과목은 비용이 0 이므로 `C[0] =
0` 으로 초기화 한다. 또한 최대 비용은 `n` 이므로 나머지는 `C[i] = n`
으로 초기화 한다. `C[]` 가 모두 채워지면 `C[(1 << n) - 1]` 이 답이다.

이제 bitmask `u` 를 이용하여 `[0..1<<n)` 를 순회하면서 다음을 반복한다.

* `int canStudy = 0` 를 선언하여 특정 `u` 에 대해 수강할 수 있는 과목을
  bit mask 형태로 저장한다.
* `canStudy` 에서 `u` 의 과목들은 제거되야 한다???
* `int sub` 를 `[canStudy..0)` 동안 순회하면서 다음을 반복한다. 이때
  부분집합 순회를 이용해야 한다.
  * `sub` 에 저장된 수강한 과목의 개수가 `k` 보다 작거나 같으면 `C[u | sub]`
    = Math.min(C[u | sub], C[u] + 1)` 를 수행한다.
  
모든 반복을 마치면 `C[(1 << n) - 1]` 가 곧 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2) O(N)
```
