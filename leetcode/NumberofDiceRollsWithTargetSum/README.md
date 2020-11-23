# Problem

[Number of Dice Rolls With Target Sum](https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/)

# Idea

주사위를 던지는 횟수 `D`, 주사위의 면수 `F`, 목표수 `T` 가 주어진다.
주사위를 `D` 번 던져서 합이 `T` 가 되는 경우의 수를 구하는 문제이다.

예를 들어 `D = 2, F = 6, T = 7` 인 경우를 살펴보자.  `1+6, 2+5, 3+4,
4+3, 5+2, 6+1` 와 같이 모두 `6` 가지가 있다.

다음과 같은 부분문제를 정의하고 재귀적으로 해결해보자.

```
int dfs(int i, int tgt)

     i: 이번에 던지는 서수
   tgt: 목표수
return: i 번째 던져서 tgt 가 나올 경우의 수
```

`i, tgt` 에 대해 overlapping subproblems 가 많다는 것을 알 수 있다.
따라서 캐시 `vector<vector<int>> C(D+1, vector<int>(TGT+1, -1)`
를 선언하여 memoization 한다.

* `i >= d - 1` 이고 `tgt <= f` 이면 `return 1` 이다.
* `int& r = C[i][tgt]` 를 수행한다. `r` 이 caching 되었다면 r 을
  리턴한다.
* `r` 이 caching 되어 있지 않으면 `i` 를 `[1..d]` 동안 순회하면서
  다음을 반복한다.
  * `tgt - j <= 0` 이면 `j` 가 너무 크다. 반복을 중단한다.
  * `tgt - j > 0` 이면 `r = (r + dfs(i+1, tgt-j))` 를 
* `r` 을 리턴한다.

이것을 iterative 하게 접근하면 조금 더 최적화 할 수 있다.

TODO

이것을 1 차원 배열을 사용하면 조금 더 최적화 할 수 있다.

TODO

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(DTF) O(DT)
```
