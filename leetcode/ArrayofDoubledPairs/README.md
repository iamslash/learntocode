# Problem

[Array of Doubled Pairs](https://leetcode.com/problems/array-of-doubled-pairs/)

# Idea

수열 `A[]` 가 주어진다. `A[]` 의 순서를 재배열 하여 `A[2*i + 1] = 2 * A[2*i]` 를 만족하도록 할 수 있는지 검증하는 문제이다.

예를 들어 `A = [3, 1, 3, 6]` 의 경우를 살펴보자. 방법은 없다.
또한 `A = [4, -2, 2, -4]` 를 살펴보자. `A = [-2, -4, 2, 4]` 이면 가능하다. 정리하면 어떤 수 `a` 와 `2*a` 가 짝을 이루고 있으면 참이다. 그러나 `a < 0` 인 경우와 `a >= 0` 인 경우 구분해서 처리해야 한다.

`map<int, int> num2cnt` 를 선언하여 `{number : count of number}` 를 저장한다. `num2cnt` 는 정렬되어 있다. 음수도 등장할 수 있다. 처음부터 순회하면서 다음을 반복한다.

* `num2cnt` 를 채운다.
* `num2cnt` 를 처음부터 순회하며 다음을 반복한다. 순회하는 수를 `a` 라 하고 `a` 는 가장 작은 값부터 방문한다.
  * `a < 0` 이면 `a` 와 짝이되는 수 `a/2` 의 개수가 충분한지 검사한다. 없다면 false 를 리턴한다. 있다면 `num2cnt[a/2] -= num2cnt[a]` 를 수행한다.
  * `a >= 0` 이면 `a` 와 짝이되는 수 `2*a` 의 개수가 충분한지 검사한다. 없다면 false 를 리턴한다. 있다면 `num2cnt[2*a] -= num2cnt[a]` 를 수행한다.

모든 반복을 마치면 true 를 리턴한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
```