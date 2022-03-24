# Problem

[Maximum Earnings From Taxi](https://leetcode.com/problems/maximum-earnings-from-taxi/)

숫자 `n`, 수열의 모음 `rides[][]` 가 주어진다. `rides[]` 는 `[start_i,
end_i, tip_i]` 와 같다. 택시는 `[1..n]` 지점을 지동할 수 있다. 수입은
`end_i - start_i + tip_i` 와 같이 계산한다. 최대의 수입이 되도록
`rides[i]` 를 선택해 보자. 그 최대의 수입을 구하라.

# Idea

예를 들어 `n = 5, rides = [[2,5,4],[1,5,1]]` 의 경우를 살펴보자.

```
     rides: 2,5,4 1,5,1
                i
maxEarning: 5 - 2 + 4 = 7       
```

따라서 답은 `7` 이다.

[knapsack problem](/fundamentals/dynamicprog/knapsack01/README.md) 과 비슷하다.

다음과 같이 풀이해 보자.

* 먼저 `rides[]` 를 `start_i` 의 오름차순으로 정렬한다.
* `long C[] = new long[n+1]` 를 선언한다. `C[a]` 에 `a` 지점까지
  이동했을 때 최대수익을 저장한다.
* `int i = 0` 을 선언하여 `C[a]` 를 순회할 때 마다 선택할 수 있는
  `rides[]` 의 시작 인덱스로 사용한다. 즉, `rides[i][0] == a` 임을
  확인하는 용도로 사용한다. `i` 는 한번 증가하면 줄어들 수 없다.
* `int a` 를 `[1..n]` 동안 순회하면서 다음을 반복한다.
  * `C[a] = max(C[a], C[a-1])` 를 수행한다.
  * `i < rides.length && rides[i][0] == a` 인 동안 다음을 반복한다.
    * `start_i, end_i, tip_i = rides[i][0], rides[i][1], rides[i][2]` 를 선언한다.
    * `rides[i]` 를 선택했을 때와 선택하지 않았을 때를 비교하여
      `C[end_i]` 에 저장한다. 즉, `C[end_i] = max(C[end_i], C[a] +
      end_i - start_i + tip_i)` 를 수행한다.
    * `i` 를 하나 증가한다.

모든 반복을 마치면 `C[n]` 이 곧 답이다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(N + KlgK) O(N)
N: n
K: rides.length
```
