# Problem

[Consecutive Numbers Sum](https://leetcode.com/problems/consecutive-numbers-sum/)

숫자 `N` 이 주어지면 연속 된 수들의 합으로 표현할 수 있는 방법의 수를
찾아라.

# Idea

예를 들어 `N = 5` 이면 답은 2 이다.

```
5 = 2 + 3
  = 5
```

만약 임의의 수 `x` 가 있다고 하자. `x` 는 연속된 수들 중 가장 작은
수이다.

``` 
 N = x + (x + 1) + (x + 2) + ... + k
   = kx + (1 + 2 + .. + k)
   = kx + k * (k - 1) / 2
  
kx = N - k*(k-1)/2

     N - k*(k-1)/2 > 0
    2N > k*(k-1)
    sqrt(2N) > k ???
```

`k = [2..sqrt(2*N))` 인 각각의 `k` 에 대해 `N - k*(k-1)/2` 를 구한다.
그리고 그 값이 `k` 로 나누어 떨어지면 `x` 를 찾은 것이다. `ans` 를
하나 증가한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(sqrt(N)) O(1)
```
