# Problem

[Statistics from a Large Sample](https://leetcode.com/problems/statistics-from-a-large-sample/)

# Idea

수열 `A[]` 가 주어진다. `i` 의 빈도수가 `A[i]` 임을 의미한다.
`A[i] > 0` 인 경우의 min, max, avg, mean, median, mode
를 구하는 문제이다. mode 는 최빈값이다. 가장 빈도가 많은 값을 말한다.

다음과 같이 `A = [0, 4, 3, 2, 2]` 의 경우를 살펴보자. 먼저 `int cnt`
를 선언하여 총 개수를 저장한다. `double sum` 을 선언하여 합을 저장한다.

```
// 0 1 2 3 4
// 0 4 3 2 2

// cnt: 11
// sum: 24
// min: 1
// max: 4
// mea: sum/cnt = (1*4 + 2*3 + 3*2 + 4*2)/11 = 24/11 = 2.18182
// mod: 1
//  m1: (cnt + 1) / 2 = 12 / 2 = 6
//  m2: 6 (same with m1 because cnt is odd)
// med: 2
```

`A[i] > 0` 인 첫번째 `A[i]` 를 찾는다. `min = i` 이다.  마지막 `A[i]`
를 찾는다. `max = i` 이다.  `mean = sum / cnt` 이다. 가장 `A[i]` 를
찾는다.  `mod = i` 이다.

`int m1, m2` 를 선언하여 다음과 같이 초기화 한다.

```
m1 = (cnt + 1) / 2;
m2 = cnt % 2 ? m1 : m1 + 1;
```

즉, `cnt` 가 홀수인 경우는 `median = m1 = m2` 이다.  `cnt` 가 짝수인
경우는 `m1 < median < m2` 이다. 두 경우 모두 `median = (m1 + m2) / 2 =
m1/2 + m2/2` 가 성립한다.

이제 `A[i]` 를 순회하면서 이전까지 개수의 합을 `prvcnt`, 현재까지
개수의 합을 `curcnt` 라 하면 `prvcnt < m1 < curcnt` 일 때 `median += i
/ 2` 를 수행하고 `prvcnt < m2 < curcnt` 일 때 `median += i / 2` 를
수행하면 `median` 을 얻을 수 있다.

```cpp
        if (prvcnt < m1 && prvcnt + A[i] >= m1)
          smed += (double)i / 2;
        if (prvcnt < m2 && prvcnt + A[i] >= m2)
          smed += (double)i / 2;
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
