# Problem

> [Maximum Population Year](https://leetcode.com/problems/maximum-population-year/)

기간의 모음 `logs[][]` 가 주어진다. `logs[i][0]` 은 시작년도,
`logs[i][1]` 은 끝년도를 의미한다. 곂치는 구간이 최대인 년도를 구하라.
곂치는 구간이 같다면 가장 작은 년도를 구하라.

제한조건은 다음과 같다.

* `1 <= logs.length <= 100`
* `1950 <= start < end <= 2050`

# Idea

예를 들어 `logs = [[1950,1961],[1960,1971],[1970,1981]]` 의 경우를 살펴보자.

```
   logs: 1950,1961 1960,1971 1970,1981
   cnts: 1950 1960 1961 1970 1971 1981
            1    1   -1    1   -1   -1
     ps:    1    2    1    2    1    0
maxYear: 1950 
```

따라서 답은 `1960` 이다.

`int[] cnts = new int[2051]` 를 선언하고 년도별 발생횟수에 대한
부분합을 저장한다. 부분합중 최대값이 처음 나타났을 때 년도가 답이된다.

문제의 조건에 의해 `1950 <= start < end <= 2050` 이므로 line sweep
으로 해결할 만 하다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(N) O(1)
```
