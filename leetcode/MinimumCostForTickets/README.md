# Problem

[Minimum Cost For Tickets](https://leetcode.com/problems/minimum-cost-for-tickets/)

# Idea

여행하는 날짜들의 모음 `days[]` 와 1 일, 7 일, 30 일 동안 여행할 수
있는 요금의 모음 `costs[]` 가 주어진다. `days` 를 모두 여행할 수 있는
최소의 요금의 합을 구하는 문제이다. `1 <= days[i] <= 365` 이다.

전형적인 dynamic programming 문제이다. 캐시 `vector<int> C(365)` 을
선언하고 인덱스 `i` 를 `1` 부터 `365` 까지 증가하면서 `C` 를 갱신한다.
이때 다음과 같은 equation 을 만들어 낼 수 있다. `C[365]` 가 답이다.

```
i is not in days[]
  C[i] = C[i-1]
i is in days[]
  C[i] = min(C[i-1] + costs[0], C[i-7] + costs[1], C[i-30] + costs[2])
```

캐시의 길이는 30 개만 있어도 된다. 인덱스 `i` 를 `days[0..n)` 동안
순회한다.  대신 인덱스의 경우 나머지 연산자를 이용하여 다음과 같이
equation 을 만들어 낼 수 있다. 그리고 마지막에 `C[days[n-1]%30]` 이
답이다.

```
i is not in days[]
  C[i%30] = C[(i-1)%30]
or
i is not in days[]
  C[i%30] = min(C[(i- 1)%30] + costs[0], 
                C[(i- 7)%30] + costs[1], 
                C[(i-30)%30] + costs[2])
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
