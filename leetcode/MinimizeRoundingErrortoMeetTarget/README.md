# Problem

[Minimize Rounding Error to Meet Target](https://leetcode.com/problems/minimize-rounding-error-to-meet-target/)

# Idea

가격들의 모음 `P[]`, 정수 `T` 가 주어진다. 이때 `P[i]` 는 소수점 이하
`3` 자리의 실수이다. `P[i]` 를 내림 혹은 올림으로 변환하여 모두 더했을
때 `T` 가 될 수 있다면 가장 적은 `sum(|rnd(P[i]) - P(i)|)` 을 구하는
문제이다.  `rnd` 는 `ceil or floor` 이다. 이때 오차의 합은 소수점 이하
3 자리의 실수이다.

`sum(rnd(P[i])) == T` 가 되는 방법을 생각해 보자. 이때 `P[i]` 의
소수점 이하의 수를 `f[i]` 라고 하자. `sum(|rnd(P[i]) - P(i)|)` 가
최소가 되기 위해서는 오차 `err(P[i])` 는 `f[i]` 혹은 `1 - f[i]` 이다.
`rnd = ceil or floor` 이기 때문이다. 그렇다면 `rnd(P[i])` 는
`floor(P[i])` 인지 `ceil(P[i])` 를 알면 답을 구할 수 있다.

`P[]` 를 처음부터 순회하면서 다음을 반복한다. float 보다는 integer
연산을 해보자.

* `P[i] * 1000` 을 하고 이것을 `1000` 으로 나눈 몫과 나머지를 `quo,
  rem` 이라고 하자. 이때 `T -= quo` 를 수행한다.
* `rem != 0` 이라면 `R` 에 삽입한다.

`int n = R.size()` 라고 하자. 모든 반복을 마치고 `T < 0 || T > n` 이면 `T` 를 만드는 것은
불가능하다. `-1` 를 리턴한다. 이제 `R[]` 를 순회하면서 `sum(rnd[R[i]]) == T` 이어야 한다.

`R[]` 를 오름차순으로 정렬하고 가장 큰 것부터 `T` 개 까지는 `1` 로
만들고 나머지는 `0` 으로 만들어야 한다. 따라서 오차의 합은 `T` 개의 
`sum(1 - R[i])` 과 `n - T` 개의 `sum(R[i])` 의 합과 같다.

다음은 `P = {0.700, 2.800, 4.900}, T = 8` 의 풀이 과정이다.

```
             T: 8
             P: 0.700 2.800 4.900

      1000 * P:   700  2800  4900
           quo:     0     2     4
           rem:   700   800   900
       
             T: 2 (8 - 2 - 4)
           n-T: 1 (3 - 2)

sum(err(R[i])): 700 + (1 - 800) + (1 - 900)
              : 1000
           ans: 1000 / 1000
              : 1.000
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
