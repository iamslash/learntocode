- [Abstract](#abstract)
- [다양한 유형의 문제들](#다양한-유형의-문제들)
- [previous, next boundary](#previous-next-boundary)
- [int floor, int ceil](#int-floor-int-ceil)
- [gcd (Greatest Common Divisor)](#gcd-greatest-common-divisor)
- [lcm (Least Common Multiple)](#lcm-least-common-multiple)
- [fast pow](#fast-pow)
- [Min Pair Plus One](#min-pair-plus-one)

----

# Abstract

- 수 이론에 대해 적어본다.

# 다양한 유형의 문제들

- 나머지연산
- 최대공약수
- 최소공배수
- 어떤 수가 소수인지 판별하는 방법
- 어떤 정수 범위 안에 들어있는 소수를 구하는 방법
- 소인수 분해를 하는 간단한 방법
- 진법 변환
- 팩토리얼
- a^b 제곱연산을 분할 정복 알고리즘과 이진수의 원리를 이용
- 행렬
- 피보나치수, 피사노 주기
- 이항계수
- 파스칼의 삼각형
- 카탈란 수
- 오일러 피 함수
- 나눗셈에서 나머지 연산
- 확장 유클리드 알고리즘

# previous, next boundary

임의의 숫자가 주어지면 다음 경계값 혹은 이전 경계값을 구하는 전략이다. 예를 들어
임의의 숫자가 주어지면 그 숫자보자 작고 15 단위로 나누어 지는 수와 그 숫자보다
크고 15 간위로 나누어지는 수를 구해보자.

```
prevBound = (num - 14) / 15) * 15

nextBound = (num / 15) * 15
```

unit 을 단위에 해당하는 수라고 하자. 그러면 다음과 같이 정리할 수 있다.

```
prevBound = (num - (unit - 1)) / unit) * unit

nextBound = (num / unit) * unit
```

* [L](/leetcode2/TheNumberofFullRoundsYouHavePlayed/README.md) | [The Number of Full Rounds You Have Played](https://leetcode.com/problems/the-number-of-full-rounds-you-have-played/)

# int floor, int ceil

double `floor()` 는 내림이고 `ceil()` 은 올림이다.

```java
$ jshell
> Math.floor((double) 3 / 3)
1.0
> Math.floor((double) 4 / 3)
1.0
> Math.floor((double) 5 / 3)
1.0

$ jshell
> Math.ceil((double) 4 / 3)
2.0
> Math.ceil((double) 5 / 3)
2.0
> Math.ceil((double) 6 / 3)
2.0
```

나누는 숫자를 `div` 라고 하자. 어떤 숫자를 `div` 로 나누고 그 값의 `floor()`
혹은 `ceil()` 를 얻고 싶다. 이 것을 int 로 해보자.

int floor 는 `div` 를 나누어 구할 수 있다.

```
$ jshell
> 3 / 3
1
> 4 / 3
1
> 5 / 3
1
```

int ceil 는 `div - 1` 를 더하고 `div` 를 나누어 구할 수 있다.

```
$ jshell
> (4 + 3 - 1) / 3
2
> (5 + 3 - 1) / 3
2
> (6 + 3 - 1) / 3
2
```

# gcd (Greatest Common Divisor)

* [Euclidean algorithm, GCD](fundamentals/numbertheory/euclideanalgorithm/README.md)

# lcm (Least Common Multiple)

```
  A = a * gcd
  B = b * gcd

lcm = a * b * gcd = A * B / gcd
```

# fast pow

숫자 `n` 이 주어지면 `2 ^ n` 를 빠르게 구해보자. `n` 은 어차피 `1` 이 되기
마련이다.

```java
long ans = 1, base = 2, mod = 1_000_000_007L;
while (n > 0) {
    if (n % 2 == 1) {
        ans = ans * base % mod;
    }
    base = base * base % mod;
    n >>= 1;
}
return (int)((ans - 2 + mod) % mod);
```

# Min Pair Plus One

> [Construct the Longest New String](/leetcode3/ConstructtheLongestNewString/)

숫자 `x, y` 가 주어진다. 똑같은 수를 `x, y` 에서 뽑는다. 둘중 큰 수가 있다면
뽑은 수에 `1` 을 더한다.

예를 들어 `2, 7` 이 주어지면 답은 `5 (2 + 2 + 1)` 이다. `2, 2` 가 주어지면 답은
`4 (2 + 2)` 이다.

```java
Math.min(x + 1, y) + Math.min(x, y + 1)
```
