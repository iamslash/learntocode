# Abstract

이항계수를 구하기 위한 여러가지 방법들 중 뤼카의 정리를 적어본다.

[binomial cofefficient](/doc/dynamic_binomial_coefficient.md)

# References

* [lucas theorem @ geeksforgeeks](http://www.geeksforgeeks.org/compute-ncr-p-set-2-lucas-theorem/)
* [나머지 연산의 곱셈 역원 @ acmicpc.net](https://www.acmicpc.net/blog/view/29)


# Idea

이항계수의 공식은 다음과 같다.

![](/_img/binom.png)

```
\begin{align*}
\binom{n}{r} &= \ _{n}C_{r} \\
\binom{n}{r} &= \frac{n!}{(n-r)!r!} \\
\binom{n}{r} &= \binom{n-1}{r-1} \binom{n-1}{r} \\
\end{align*}
```

100 C 50의 답은 100891344545564193334812497256이다.
long long 으로도 overflow를 막을 순 없다.
나머지 연산자를 다음과 같이 사용할 수 밖에 없다.

![](/_img/binom_modular.png)

```
\binom{n}{r} \mod m = ( \left( \binom{n-1}{r-1} \mod m \right )  + \left( \binom{n-1}{r} \mod m \right) ) \mod m
```

그러나 n = 1000000000, r = 500000000 인 경우
nCr을 연산하는데 매우 긴 시간이 걸릴 것이다.

그래서 뤼카의 정리를 이용하여 시간복잡도와
공간복잡도를 개선해 보자.
뤼카의 정리는 다음과 같다.

![](/_img/lucas_eq_1.png)

![](/_img/lucas_eq_2.png)

```
예를 들어 1000 C 900 % 13 의 경우를 살펴보자.

1000 = 5 * 13^{2} + 11 * 13^{2} + 12 * 13^{0}
900  = 5 * 13^{2} +  4 * 13^{2} +  3 * 13^{0}
1000 C 900 % 13 = 5C5 * 11C4 * 12C3 % 13
                = 8
python을 이용해서 1000 C 900 % 13을 구해보았다.
>>> factorial(11) / factorial(7) * factorial(4) * factorial(12) / factorial(9) * factorial(3) % 13
8
```

다음은 앞서 언급한 알고리즘을 구현한 것이다.  nCr_dp의 n은 항상
p미만이기 때문에 nCr_dp의 시간복잡도는 `O(p^{2})`이다. p진법으로
자리변환 한 것의 개수가 `\log_{p}n`이므로 전체 시간복잡도는 `O(p^{2}
\log_{p}n)`이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
??? ???
```