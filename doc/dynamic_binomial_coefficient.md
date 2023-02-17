- [Abstract](#abstract)
- [Permutation](#permutation)
- [Combination](#combination)
- [Binomial Theroem](#binomial-theroem)
- [Binomial Coefficient](#binomial-coefficient)
- [Implementation](#implementation)
  - [Factorials](#factorials)
  - [파스칼의 삼각형을 이용한 방법](#파스칼의-삼각형을-이용한-방법)
  - [나머지 연산자 곱셈의 역원(modular multiplicative inverse)을 이용한 방법](#나머지-연산자-곱셈의-역원modular-multiplicative-inverse을-이용한-방법)
  - [lucas' theorem을 이용한 방법](#lucas-theorem을-이용한-방법)

----

# Abstract

순열, 조합, 이항정리, 이항계수에 대해 정리한다.

# Permutation

`n` 개에서 `r` 개를 중복하지 않고 순서를 고려하여 골라내는 방법을 순열이라고
한다. `nPr = n x (n-1) x (n-2) x ... x (n-r+1)` 이다. 따라서 다음과 같은 정리를
유도할 수 있다.

![](/_img/dynamic_permutation.png)

```math
_{n}P_{r} = n (n-1) (n-2) \cdot\cdot\cdot (n-r+1) = \frac{n!}{(n-r)!}
```

# Combination

`n` 개에서 `r` 개를 순서없이 골라내는 방법과 같다. `n` 개에서 `r` 개를 선택하는
순열을 `r` 개의 순서를 고려한 경우의 수 `r!` 로 나눈 것과 같다.

![](/_img/dynamic_combination.png)

```latex
_{n}C_{r} = \frac{_{n}P_{r}}{r!} = \frac{n!}{r!(n-r)!}
```

- `n` 개에서 `r` 개를 선택하는 것은 `n` 개에서 `n-r` 개를 선택하지 않는 것을
  선택하는 것과 가짓수가 같다.

![](/_img/dynamic_combination_1.png)

```latex
_{n}C_{r} = _{n}C_{n-r}
```

- `n` 개중 한개를 고정한다. 이제 `n` 개중 `r` 개를 선택하는 가짓수는 그 한개가 `r` 에 포함된 경우, 포함되지 않은 경우와 같이 `2` 가지로 나눠진다. 각각 `n-1Cr-1`, `n-1Cr` 로 표현할 수 있다. 

![](/_img/dynamic_combination_2.png)

```latex
_{n}C_{r} = _{n-1}C_{r-1} + _{n-1}C_{r}
```

# Binomial Theroem

[이항정리 | 나무위키](https://namu.wiki/w/%EC%9D%B4%ED%95%AD%EC%A0%95%EB%A6%AC)

`(a + b)^n` 형태의 다항식을 전개하면 다음과 같다. 이 것을 이항정리라고 한다.

![](img/![](img/2023-02-17-13-50-13.png).png)

# Binomial Coefficient

`(a + b)^n` 형태의 다항식을 전개했을 때 각 항 (`a^r b^{n-r} (0 <= r <= n 인
정수)`) 의 계수를 이항계수라고 한다. 

![](/_img/dynamic_binomial_coefficient.png)

```latex
\binom{n}{r} = \binom{n-1}{r-1} + \binom{n-1}{r}
```

# Implementation

Combination 을 구현 할 수 있다면 Binomial Coefficient 역시 구현할 수 있다.
Factorials, 파스칼의 삼각형, 뤼카의 정리, 나머지 연산자 곱셈의 역원을 이용한
방법 등을 기술한다.

## Factorials

* [L](/leetcode2/KthSmallestInstructions/README.md) | [Kth Smallest Instructions](https://leetcode.com/problems/kth-smallest-instructions/)

----

예를 들어 `nCr` 을 factorial 을 이용하여 표현하면 다음과 같다.

```cpp
nCr = n! / r! * (n-r)!
5C3 = 5 * 4 * 3 / 3 * 2 *1
    = 3 * 4 * 5 / 1 * 2 * 3
    = 1 * 3 / 1 * 4 / 2 * 5 / 3
```

위의 수식을 두개의 인덱스 `i, j` 를 이용하여 구현하면 다음과 같다.

```cpp
int combi(int n, int r) {
  int64_t ans = 1;
  for (int i = 1, j = n - r + 1; i <= r; ++i, ++j) {
    ans = ans * j / i;
  }
  return ans;
}
```

## 파스칼의 삼각형을 이용한 방법

* [Dynamic Programming | Set 9 (Binomial Coefficient) @ geeksforgeeks ](http://www.geeksforgeeks.org/dynamic-programming-set-9-binomial-coefficient/)

파스칼의 삼각형은 다음과 같다. 숫자들과 nCr의 관계를 잘 살펴보자.

![](/_img/paskal_triangle.png)

다음은 파스칼의 삼각형을 이용하여 이항계수를 구현한 것이다.  트리의 깊이가 곧
`n` 과 같다. overflow 를 막기 위해 나머지 연산자를 이용하였다. 시간복잡도는
`O(nr)` 이다.

```cpp
// in every line first value is always 0 + 1 pattern
// C[1] = C[1] + C[0] = 0 + 1 = 1
//   C[2] = C[2] + C[1] = 0 + 1 = 1
//   C[1] = C[1] + C[0] = 1 + 1 = 2
//     C[3] = C[3] + C[2] = 0 + 1 = 1
//     C[2] = C[2] + C[1] = 2 + 1 = 3
//     C[1] = C[1] + C[0] = 2 + 1 = 3
// pascal triangle
int nCr_dp(int n, int r, int p) {
  int C[r+1] = {0,};
  C[0] = 1; // top row of pascal triangle
  for (int i = 1; i <= n; ++i) {
    for (int j = std::min(i, r); j > 0; --j) {
      // nCj = (n-1)Cj + (n-1)C(j-1)
      C[j] = (C[j] + C[j-1]) % p;
    }
  }
  return C[r];
}
```

## 나머지 연산자 곱셈의 역원(modular multiplicative inverse)을 이용한 방법

나머지 연산자에 대한 곱셈의 역원(modular multiplicative inverse) 을
이용하여 이항계수를 구해보자. 나머지 연산자에 대한 곱셈의 역원은
페르마의 소정리를 이용해서 구하면 전체 시간복잡도를 더욱 개선할 수 있다.

* [나머지 곱셈의 역원 @ TIL](https://github.com/iamslash/TIL/tree/master/numbertheory#나머지-곱셈의-역원-modular-multiplicative-inverse)
* [나머지 곱셈의 역원을 페르마의 소정리를 이용하여 구하는 법 @ learntocode](/fundamentals/numbertheory/modulararithmatic/README.md)
* [Compute nCr % p | Set 3 (Using Fermat Little Theorem) @ geeksforgeeks](http://www.geeksforgeeks.org/compute-ncr-p-set-3-using-fermat-little-theorem/)
* [Modular Exponentiation (Power in Modular Arithmetic) @ geeksforgeeks](http://www.geeksforgeeks.org/modular-exponentiation-power-in-modular-arithmetic/)

```
nCr 을 빠르게 구해보자. 나누고 나머지 연산하는 것은 곱하고 나머지
연산하는 것으로 바꾸어야 연산의 결과가 정수에 닫혀있어야 하기 때문이다. 
참고로 나누고 나머지 연산은 실수에 닫혀있다.

nCr = (n! / ((n-r)! * r!)) % p
    = ((n! % p) * ((n-r)!^{-1} % p) * r!^{-1} % p) % p
    = ((n! % p) * modinv((n-r)!, p) * modinv(r!, p)) % p

modinv(a, p) 는 a 의 inverse 를 p 로 modulo 한다는 의미이다. 
페르마의 소정리를 이용하여 modinv() 를 구해보자.

a^{p-1} % p = 1 % p (Fermat's little theorem)
a^{p-1} * a^{-1} % p = 1 * a^{-1} % p 
a^{p-2} % p = a^{-1} % p
 a^{-1} % p = a^{p-2} % p

따라서 

modinv(a, p) = a^{-1} % p
             = a^{p-2} % p

nCr = ((n! % p) * ((n-r)!^{p-2} % p) * (r!^{p-2} % p) % p
```

앞서 언급한 알고리즘의 구현은 다음과 같다. 반드시 p 는 n 보다 커야 한다.
그렇지 않으면 modinv 의 첫번재 인자가 팩토리얼이기 때문에 modinv 의
결과가 `0` 이 될 수 있다. power 의 시간복잡도는 `O(\log_{2}n)` 이기 때문에
전체 시간복잡도는 `O(n \log_{2}n)` 이다.  만약 `fac[]` 를 한번만 만들어
두고 재활용한다면 시간복잡도는 `O(\log_{2}n)` 이다.

```cpp
int power(int x, unsigned int y, int p) {
  int r = 1;
  while (y > 0) {
    if (y & 1) {
      r *= x;
      r %= p;
    }
    y = y >> 1;
    x *= x;
    x %= p;
  }
  return r;
}

int modinv(int n, int p) {
  return power(n, p-2, p);
}

int nCr_ferma(int n, int r, unsigned int p) {
  if (r == 0)
    return 1;
  int fac[n + 1];
  fac[0] = 1;
  for (int a = 1; a <= n; ++i) {
    fac[i] = fac[a-1] * a % p;
  }
  return (fac[n] * modinv(fac[r], p) % p * modinv(fac[n-r], p) % p) % p;
}
```

## [lucas' theorem](number_lucas.md)을 이용한 방법

파스칼의 삼각형을 이용한 방법보다 시간복잡도를 `O(p^{2} \log_{p}n)` 으로 개선 할
수 있다. 이때 `p` 가 너무 크면 파스칼의 삼각형을 이용한 방법보다 시간복잡도가 클 수
있다. lucas' theorem 은 `p` 가 작은 경우 사용한다. 

`p` 가 너무 큰경우 `(n < p)` 나머지 연산자 곱셈의 역원을 이용한 방법이 더욱
효율적이다. `n` 보다 `p` 가 작거나 같은 경우는 페르마의 소정리를 이용하여 나머지
연산자 곱셈의 역원을 구하면 결과가 `0` 일 수 있다.
