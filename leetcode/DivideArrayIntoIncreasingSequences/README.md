# Problem

[Divide Array Into Increasing Sequences](https://leetcode.com/problems/divide-array-into-increasing-sequences/)

# Idea

오름차순으로 정렬된 수열 `A[]` 와 숫자 `K` 가 주어진다. 서로 다른
숫자가 오름차순으로 정렬된 subsequence 를 만들어 볼 수 있는지 검증하는
문제이다. 각 subsequence 는 길이가 최소 `K` 이다.

예를 들어 `A = [1, 2, 2, 3, 3, 4, 4], K = 3` 의 경우를 살펴보자.  `[1,
2, 3, 4], [2, 3, 4]` 이므로 답은 `true` 이다.

또한 `A = [5, 6, 6, 7, 8], K = 3` 의 경우를 살펴보자. 방법이 없으므로
답은 `false` 이다.

위의 예를 통해 몇가지 규칙을 발견할 수 있다.

* `A[i]` 중 중복되는 것들은 같은 subsequence 에 포함될 수 없다.
* `A[i]` 중 중복되는 것들 중 가장 많이 중복되는 개수를 `d` 라고 하자.
* `n >= d * k` 이면 `true` 이고 그렇지 않다면 `false` 이다.

예를 들어 `K = 2` 인 경우를 생각해 보자. 

* `A = [1, 2]` 이면 `true` 이다.
  * `d = 1, K = 2, n = 2` 
* `A = [2, 2]` 이면 `false` 이다.
  * `d = 2, K = 2, n = 2` 

# Implementation

* [c++11](a.cpp)
* [java8](Solution.java)
* [python3](a.py)

# Complexity

```
O(N) O(1)
```
