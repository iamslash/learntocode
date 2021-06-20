# Problem

[subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/description/)

수열 `A[]` 와 숫자 `K` 가 주어진다. `A` 의 subarray 중 합이 `K` 와
같은 것들의 개수를 구하는 문제이다.

# Idea

예를 들어 `A = 1 1 1, K = 2` 인 경우 `i == 2` 일 때를 살펴보자.

```
         _
      A: 1 1 1
             i
    sum: 1 2 3
```

* `A[0] + A[1] + A[2]` 를 모두 더하고 `sum` 이라고 하자.
* `sum - K` 가 이전에 발생한 횟수를 얻어온다. 그 수가 0 보다 크다는 것은 `A[2]` 를 포함한 subarray 중 합이 `K` 인 것이 있다는 의미이다.

다음과 같은 변수를 선언한다.

* `int cnt`: 답을 저장한다.
* `int sum`: 지금까지 출현한 `A[i]` 의 합을 저장한다.
* `Map<Integer, Integer> freqMap`: `sum` 의 발생횟수를 저장한다.

인덱스 `i` 를 `[0..n)` 동안 순회하면서 다음을 반복한다.

* `sum` 에 `A[i]` 를 더한다.
* 이전에 `sum - K` 가 발생한 횟수를 `cnt` 에 더한다.
* `sum` 의 발생횟수를 하나 증가한다. 문제의 조건에 의해 `-1000 <= A[i] <= 1000` 이므로 `sum` 은 증가 혹은 감소할 수 있음을 주의하자.

모든 반복을 마치면 `cnt` 가 곧 답이다.

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

# Complexity

```
O(N) O(N)
```
