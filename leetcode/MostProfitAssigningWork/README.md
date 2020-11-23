# Problem

[Most Profit Assigning Work](https://leetcode.com/problems/most-profit-assigning-work/)

# Idea

어떤 일에 대해 어려움의 정도와 수익이 `D[], P[]` 로 주어진다.  그리고
일하는 사람의 능력이 `W[]` 로 주어진다. `W[]` 의 일꾼들이 자신의
능력을 최대로 끌어올려서 최대의 수익을 냈을 때 그 수익을 구하는
문제이다.

`vector<pair<int, int>> jobs` 를 선언하고 `D[i], P[i]` 를 삽입한다.
그리고 오름차순으로 정렬한다. `W[]` 역시 오름차순으로 정렬한다.

`W[]` 를 인덱스 `i` 를 이용하여 순회하면서 `W[i]` 가
최대로 거들 수 있는 수익을 알아내고 이것을 `r` 에 누적하여
더한다. 마침내 `r` 이 답이다.

공간복잡도를 조금 희생하고 시간복잡도를 개선할 수 있다. 어려움의
범위는 `1 <= D[i] <= 10000` 이다. `D[i]` 의 최대값을 `maxdiff`
에 저장하고 캐시 `vector<int> C(maxdiff+1, 0)` 을 선언한다.

`C[i]` 에 어려움의 정도가 `D[i]` 일 때 거둘 수 있는 최대수익을
저장한다. 다음과 같이 두번의 반복문으로 구할 수 있다.

```cpp
for (int i = 0; i < D.size(); ++i)
  C[D[i]] = max(C[D[i]], P[i]);
for (int i = 1; i < D.size(); ++i)  
  C[i] = max(C[i], C[i-1]);
```

이제 일꾼의 능력 `W[i]` 를 알면 가능한 최대수익을 알 수 있다.
단, `W[i] >= maxdiff` 이면 `C[maxdiff]` 가 수익이된다.


# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```