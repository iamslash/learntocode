# Problem

[Maximum Performance of a Team](https://leetcode.com/problems/maximum-performance-of-a-team/)

숫자 `n, k`, 수열 `speed[], efficiency[]` 가 주어진다.  `n` 명의
일꾼들이 있고 각각 속도는 `speed[i]` 이고 효율성은 `efficiency[i]`
이다. 최대 `k` 명의 일꾼들을 선택할 수 있다. 일꾼들의 성과는 다음과
같이 계산한다.

* `performance = sum of speed * min of efficiency`

최대 성과를 구하라.

# Idea

예를 들어 `n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2],
k = 2` 의 경우를 살펴보자.

```
         k: 2
     speed: 2 10 3 1 5 8
efficiency: 5 4 3 9 7 2

sort efficiency, speed by desc

              i    j
efficiency: 9 7 5  4 3 2
     speed: 1 5 2 10 3 8         
```

따라서 답은 `(10 + 5) * min(4, 7) = 60` 이다.

`vector<pair<int, int>> effSpds` 를 선언하여 `{efficiency[i],
speed[i]}` 를 저장한다. 그리고 내림차순으로 정렬한다.

`priority_queue<int, vector<int>, greater<int>> pq` 를 선언하여
`speed[i]` 를 내림차순으로 유지한다. `pq.top()` 은 가장 적은 `speed`
를 의미한다. `pq.size() > k` 이면 `pq.pop()` 을 하여 `k` 개의 가장 큰
`speed` 를 유지한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(N)
```
