# Problem

[Maximum Matrix Sum](https://leetcode.com/problems/maximum-matrix-sum/)

2 차원 수열 `matrix[][]` 가 주어진다. 인접한 두수에 대해 동시에 부호를
바꿀 수 있다. 모든 합이 최대가 되었을 때 그 최대 합을 구하라.

# Idea

예를 들어 `matrix = [[1,-1],[-1,1]]` 의 경우를 살펴보자.

```
 1 -1    -1 1    1 1 
-1  1    -1 1    1 1
```

따라서 답은 `-2` 이다.

동작을 무수히 할 수 있기 때문에 다음의 규칙을 발견할 수 있다.

* 음수가 짝수 라면 모두 양수로 바꿀 수 있다.
* 음수가 홀수 라면 마지막 하나의 숫자만 음으로 바꿀 수 있다. 가장 작은 수를 선택하자.

다음과 같이 생가해 보자.

* `int absSum = 0` 을 선언하여 모든 원소의 절대값을 더한 값을 저장한다.
* `int negCnt = 0` 을 선언하여 음수의 개수를 저장한다.
* `negCnt` 가 짝수 이면 `absSum` 이 답이다.
* `negCnt` 가 홀수 이면 `absSum - minVal - minVal` 이 답이다. `absSum`
  에 이미 `minVal` 이 포함되어 있기 때문에 2 번 빼야 한다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(N^2) O(1)
```
