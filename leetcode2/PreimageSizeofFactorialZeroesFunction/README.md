# Problem

[Preimage Size of Factorial Zeroes Function](https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/)

숫자 `K` 가 주어진다. 함수 `f(x)` 는 `x!` 의 trailing zeroes 개수를
리턴한다. 참고로 `0!` 는 `1` 이다. `f(x) = K` 가 되는 숫자의 개수를
구하라.

# Idea

예를 들어 `K = 0` 인 경우를 살펴보자. `0!, 1!, 2!, 3!, 4!` 이 모두
trailing zeroes 가 0 개 이다. 따라서 답은 `5` 이다.

`x!` 의 숫자들을 소인수 분해했을 때 `2` 와 `5` 가 한쌍이 있다면 하나의
trailing zero 에 대응한다. 예를 들어 `5!` 를 살펴보자.

```
5! = 1 * 2 * 3 * 4 * 5
   = 1 * 2 * 3 * 2 * 2 * 5
   = 12 * 10
   = 120
10!= 5! * 6 * 7 * 9 * 10
   = 453,600
```

`x!` 의 경우 모든 수들을 소인수 분해했을 때 `2` 보다는 `5` 의 개수가
많다.  따라서 `5` 의 개수를 구하면 trailing zero 의 개수와 같다. `x!`
에서 5 의 개수는 다음과 같이 구한다. 

```cpp
while (x > 0) {
  ans += x / 5;
  x /= 5;
}
```

It's too difficult.

# Implementation

* [c++11](a.cpp)

# Complexity

```
```
