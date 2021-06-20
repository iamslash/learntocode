# Problem

[subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/description/)

수열 `A[]` 와 숫자 `K` 가 주어진다. `A` 의 subarray 중 합이 `K` 와
같은 것들의 개수를 구하는 문제이다.

# Idea


예를 들어 `A = 1 1 1, K = 2` 인 경우를 살펴 보자. `[0..1], [1..2]` 와
같이 두가지 경우가 가능하다.

먼저 `unordered_map<int, int> ump = {{0, 1}}` 를 선언하여 `{sum of
A[i] : cnt of subarray with K}` 를 저장한다. `int cnt = 0` 을 선언하여
구하고자 하는 sbarray 의 개수를 저장한다. `int sum = 0` 을 선언하여
`A[i]` 를 더한다. `A[i]` 를 순회하다가 `sum - K == 0` 이면 최초 합이 K
인 subarry 를 발견한 셈이 된다. `ump[0] == 1` 이므로 `cnt +=
ump[sum-K]` 를 수행한다. 또한 다음 `sum` 을 위해 `ump[sum]++` 해야
한다.

이것을 테이블로 표현해 보면 다음과 같다???

| i | A[i] | sum | subarray   | ump[sum-K] | ump |
|---|------|-----|------------|------------|-----|
|   |      | 0   | `{}`       |            | `{0: 1}`   |       
| 0 | 1    | 1   | `1`        |      0     | `{0: 1, 1: 1}` | 
| 1 | 1    | 2   | `11 1`     |      1     | `{0: 1, 1: 1, 2: 1}` | 
| 2 | 1    | 3   | `111 11 1` |      1     | `{0: 1, 1: 1, 2: 1, 3: 1}` | 

다음과 같이 구현해 보자.
인덱스 `i` 를 이용하여 `A` 를 순회하며 다음을 반복한다.

* `sum` 에 `A[i]` 를 더한다.
* `sum - K` 가 `ump` 에 있다면 `ump[sum-K]` 만큼 subarray 를 만들 수 있다는 의미이다. `cnt += ump[sum-K]` 를 수행한다.
* `ump[sum]` 를 하나 증가한다.

다음은 `A = 1 1 1, K = 2` 의 풀이 과정이다.

```
              i          i          i
  A: 1 1 1    1 1 1    1 1 1    1 1 1
sum: 0        1        2        3
cnt: 0        0        1        2
ump: 0        0 1      0 1 2    0 1 2 3
     1        1 1      1 1 1    1 1 1 1
```

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

# Complexity

```
O(N) O(N)
```
