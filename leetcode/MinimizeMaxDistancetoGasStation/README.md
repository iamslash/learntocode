# Problem

[Minimize Max Distance to Gas Station](https://leetcode.com/problems/minimize-max-distance-to-gas-station/)

# Idea

수열 `S[]` 와 숫자 `K` 가 주어진다. `S[i]` 를 주유소 `i` 의 위치라고
하자.  이때 인접한 주유소 사이의 최대 거리를 `D` 라고 하자. `k` 만큼의
주유소를 더 건설할 때 최소 `D` 를 구하는 문제이다. 그리고 `0 <= S[i]
<= 10^8` 이다. 또한 답의 오차범위는 `0 ~ 10^-6` 이다.

`D` 는 `0` 과 `10^8` 사이의 값이다. `lo = 0, hi = 10^8, mi` 를
선언하고 `lo + 0.000001 < hi` 동안 binary search 를 이용하여 가장 작은
`D` 를 찾아내자.

예를 들어 `S[] = (1, 2, 3, 4, 5, 6, 7, 8, 9, 10), K = 9` 라고 해보자.
`mi = 2` 라면 현재 `mi` 보다 더욱 작은 `D` 를 찾기 위해 필요한 주유소 개수 `need` 를 구해보자.

`need <= K` 이면 `mi` 는 더욱 작아도 된다. 따라서 `hi = mi` 하고 더
검색하자.

`need > K` 이면 `mi` 는 더욱 커야 한다. 따라서 `lo = mi` 하고 더
검색하자.

`need` 는 인덱스 `i` 를 이용하여 `S[]` 를 순회하면서 다음과 같이
구한다.

```
need += (int)((S[i+1] - S[i]) / mi);
```

예를 들어 `S[] = (1, 2, 3, 4), K = 3` 라고 해보자.  만약 `mi = 2` 이면 더욱 작은 `D` 를 찾기 위해 필요한 주요소 개수 `need = 3` 이다. `need <= K` 이므로 `mi` 는 더욱 작아질 수 있다. 그러나 `mi = 0.5` 이면 `need = 6` 이다. `need > K` 이므로 `mi` 는 작아질 수는 없고 더욱 커져야 한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(1)
```
