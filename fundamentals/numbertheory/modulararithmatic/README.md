# Abstract

나머지 연산자 `%` 에 대해 적는다.

# Add

두 정수 `a, b` 에 대하여 `(a + b) % M` 는 어떻게 구할 수 있을까?

```
a = xM + a'
b = yM + b'
a + b = (x + y)M + (a' + b')
a + b 를 M으로 나눈 나머지는 a' + b'을 M으로 나눈 나머지와 같다.
a' = a % M
b' = b % M
따라서 (a + b) % M = ((a % M) + (b % M)) % M
```

`A[]` 에 담겨있는 정수들을 모두 더하고 마지막 여덟자리를 구해 보자.  앞서
언급한 `%` 의 덧셈 성질을 활용해 보자. `A[]` 를 차례대로 순회하면서 각
원소에 대해 `10^8` 으로 나눈 후 나머지를 더해간다. 두수를 더할 경우 다시
`10^8` 으로 나누어 나머지를 다음 덧셈에 이용한다.

다음 코드를 참고하자. `A[]` 는 `64bit` 의 정수들이 담겨
있지만 `32bit` 정수를 이용하여 `10^8` 으로 나눈 나머지를
문제 없이 구할 수 있다.

```c
long A[N];
int r = 0;

for (int i = 0; i < N; ++i) {
  r += A[i] % sizeof(int);
  r %= sizeof(int);
}

```

# Sub

```
(a - b) % M = ((a % M) - (b % M)) % M```
```

# Mul

```
(a X b) % M = ((a % M) X (b % M)) % M```
```

# Div

* [나머지 연산의 곱셈 역원 @ acmicpc.net](https://www.acmicpc.net/blog/view/29)
* [나머지 연산 내 곱셈 역원](http://zetacode.com/math/2016/04/22/modular-multiplicative-inverse.html)

`(a / b) % M` 는 어떻게 구할 수 있을까?  앞서 언급한 바와 같이 나머지
연산자는 덧셈, 뺄셈, 곱셈에 대해서 분배 법칙이 성립한다. 하지만
나눗셈은 그렇지 않다. 덧셈, 뺄셈, 곱셈은 정수에 닫혀있지만 나눗셈은
정수에 닫혀있지 않고 실수에 닫혀있기 때문에 `a` 를 `b` 로 나누면 정수라는
보장이 없다. 식을 적당히 변형해서 나눗셈을 곱셈으로 표현하여 해결해보자.

```
(a / b) % M = (a * b^{-1}) % M
            = ((a % M) * (b^{-1} % M)) % M
b^{-1} % M 을 b 의 나머지연산에 대한 곱셈의 역원
(modular multiplicative inverse) 이라 하고 
modinv(b, M)이라고 표기하자.
modinv(b, M)을 구하면 다음과 같이 전개해서 해결한다.

(a / b) % M = ((a % M) * modinv(b, M)) % M
```

나머지 곱셈의 역원의 개념은 어렵다. 기억이 나지 않는다면
다음의 링크를 읽고 돌아오자.
[나머지 곱셈의 역원 @ TIL](https://github.com/iamslash/TIL/tree/master/numbertheory#나머지-곱셈의-역원-modular-multiplicative-inverse)

나머지 곱셈의 역원(modular muliplicative inverse)를 구하는 
방법은 무식한 방법, 페르마의 소정리를 이용한 방법,
확장 유클리드를 이용한 방법등이 있다.

앞서 언급한 것들 중 페르마의 소정리를 이용한 방법이 구현이 간단하다.

## 무식한 방법 (brute force)

```
b^{-1}은 b의 곱셈의 역원이기 때문에
b * b^{-1} ≡ 1 (mod M)
b * x      ≡ 1 (mod M)

다음과 같이 반복문을 통해 x를 구할 수 있다.

for (int i = 1; i < M; ++i) {
    if ((b * i) % M == 1) {
        x = i;
    }
}

예를 들어서 (7 / 3) % 4 를 구해보자.

먼저 3의 나머지에 대한 곱셈의 역원
(modular multiplicative inverse)를 구해보자.

3 * 1 % 4 = 3
3 * 2 % 4 = 2
3 * 3 % 4 = 1

3이 3의 나머지에 대한 곱셈의 역원이다.

(7 / 3) % 4 = ((7 % 4) * (3)) % 4
            = 3
```

## 페르마의 소정리(Fermat's little theorem)을 이용한 방법

```
페르마의 소정리는 다음과 같다.
정수 a, p가 서로소일때 
a^{p-1} % p = 1

양변에 a^{-1}를 곱하자.
a^{p-1} * a^{-1} % p = 1 * a^{-1} % p 
a^{p-2} % p = a^{-1} % p 

a를 b로 p를 M로 교체하면

b^{-1} % M = b^{M-2} % M
(a / b) % M = ((a % M) * (b^{M-2} % M)) % M
단 b와 M은 서로소이어야 한다.

예를 들어서 (7 / 3) % 4 를 구해보자.
3과 4가 서로소 이므로
(7 / 3) % 4 = ((7 % 4) * (3^{4-2} % 4)) % 4
            = (3 * (9 % 4)) % 4
            = (3 * 1) % 4
            = 3
```

## 확장 유클리드 호제법 (Extended Euclidean Algorithm)을 이용한 방법

```
확장 유클리드 호제법은 다음과 같다.
베주의 정의 (bezout's identity) ax + by = gcd(a, b)의 
(x, y) 를 구하는 방법이다.

b * b^{-1} ≡ 1 (mod M) 이다.
이때 b와 M은 서로소이어야 한다.

b^{-1}를 x라고 하면
bx % M  = 1
bx = My + 1
bx - My = 1
bx + My = 1 (y는 음수도 가능하기 때문에)
b와 M은 서로소이므로 gcd(b, M) = 1이다.
bx + My = gcd(b, M) 
위 식은 확장 베주의 항등식과 같다.
x 즉 b^{-1}를 확장 유클리드 호제법을 이용하여 구할 수 있다.
```

[extended euclidean algorithm](fundamentals/numbertheory/exeuclideanalgorithm/README.md)

다음의 코드를 이용하여 x를 구하자.

* [c++11](a.cpp)

```
예를 들어서 (7 / 3) % 4 를 구해보자.

먼저 3의 나머지에 대한 곱셈의 역원
(modular multiplicative inverse)를 구해보자.

앞서 언급한 식 bx + My = gcd(b, M)을 이용하자.
3x + 4y = gcd(3, 4) 을 만족하는 x를
확장 유클리디안 호제법을 이용하여 구하자.

x가 -1이고 y가 1일때 3 * -1 + 4 * 1 = 1을 만족한다.
따라서 x는 -1이고 이것은 3의 나머지에 대한 곱셈의 역원이다.

(7 / 3) % 4 = ((7 % 4) * (-1)) % 4
            = -1
            = 3 (-1 + 4)
```
