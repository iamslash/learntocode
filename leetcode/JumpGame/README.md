# Problem

[Jump Game](https://leetcode.com/problems/jump-game/)

# Idea

수열 `A[]` 가 주어진다. `A[0]` 에서 부터 시작해서 `A[n-1]` 에 도착할
수 있는지 검증하는 문제이다. `i` 에 도착하면 `[1..A[i]]` 만큼
오른쪽으로 jump 할 수 있다.

사다리 바꿔올라가기 와 같다.

예를 들어 `A = [2, 3, 1, 1, 4]` 를 살펴보자.

```
A: 2 3 1 1 4
    ----
      ------
        --
          --
```

two pointers 를 이용하여 해결해 보자.

`int i, j` 를 선언하다. `j` 는 현재 가장 멀리 갈 수 있는
인덱스이다. `i` 를 처음부터 끝까지 순회하면서 다음을 반복한다.

* `i > j` 이면 더이상 갈 수 있는 방법이 없다는 의미이다. `return
  false` 를 수행한다.
* 최대 어디까지 갈 수 있는지 udpate 한다. 즉, `j = max(j, i + A[i])`
  를 수행한다.

모든 반복을 마치면 `j >= n - 1` 이 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
