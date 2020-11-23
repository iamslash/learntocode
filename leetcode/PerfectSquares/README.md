# Problem

* [Perfect Squares @ leetcode](https://leetcode.com/explore/interview/card/top-interview-questions-hard/121/dynamic-programming/863/)

숫자 `n` 이 주어진다. 완전제곱수의 합으로 표현해 보자. 완전제곱수의
개수가 최소일 때 그 개수를 구하라.

# Dynamic Programming

## Idea

`vector<int> C(n+1, INT_MAX)` 를 선언하여 숫자 `i` 를 구성하는 perfect
squares 의 최소 개수를 저장한다.

이제 인덱스 `i` 를 선언하여 `[1..n]` 를 순회하며 다음을 반복한다.

* 인덱스 `j` 를 선언하여 `j*j <= i` 인 동안 `j++` 를 수행하며 다음을
  반복한다.
  * `C[i] = min(C[i], C[i - j*j] + 1)`
  
모든 반복을 마치면 `C[n]` 이 답이다.

다음은 `n = 9` 인 경우의 풀이과정이다.

```
                     i
n: 0 1 2 3 4 5 6 7 8 9 10 11 12
C: 0 1 2 3 1 2 3 4 2 1
```

## Implementation

* [c++11](a.cpp)
* [py3](a.py)

## Complexity

```
O(N^2) O(N)
```

# Lagrange's four squares Idea

## Idea

Lagrange's four squares theorem 은 어렵다.

Lagrange's four squares theorem 에 의해 모든 자연수 `n` 은 최대 4 개
자연수의 제곱의 합으로 표현할 수 있다.  따라서 답은 1, 2, 3, 4 중
하나이다. 다음과 같은 순서로 검사해본다.

첫번째 `n = a^2` 를 만족하는 자연수 `a` 가 존재하면 답은 1 이다.

두번째 `n = 4^k * (8 * m + 7)` 를 만족하는 자연수 `k, m` 이 존재하면
답은 3 이다.  이것은 [lagrange 에 의해
증명](http://mathworld.wolfram.com/LagrangesFour-SquareTheorem.html)되었다고
한다.  이 과정에서 `n` 은 4 로 나누떨어지지 않을 때까지 4 로
나누어진다. 즉 2비트씩 오른쪽으로 이동한다.

세번째 `n = b^2 + b^2` 를 만족하는 자연수 `b` 가 존재하면 답은 2 이다.

네번째 그외의 경우 답은 3 이다.

## Implementation

* [c++](lagrange.cpp)

## Complexity

```
O(1) O(1)
```
