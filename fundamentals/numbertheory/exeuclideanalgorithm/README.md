# Abstract

확장 유클리디안 알고리즘(extended Euclidean algorithm)에 대해 적는다.

# Idea

베주의 정의 (bezout's identity) `ax + by = gcd(a, b)` 의 
`(x, y)` 를 구하는 방법이다.

```
gcd(a, b)   = gcd(b, a%b)

gcd(a, b)   = ax + by 

gcd(b, a%b) = b * x_{1} + a%b * y_{1}  (a % b = a - qb, q = a / b)
            = b * x_{1} + (a - a/b*b) * y_{1}
            = a * y_{1} + b (x_{1} - a/b*b*Y_{1})
            
ax + by     = a * y_{1} + b (x_{1} - a/b*b*Y_{1})

x = y_{1}                                -----(1)
y = x_{1} - a/b*b*Y_{1}                  -----(2)

gcd(a, b) 는 gcd(?, 0)까지 재귀할 것이다.
gcd(?, 0) = ? * 1 + 0 * 0 이라고 할 수 있다.
이때 x_{1} = 1, y_{1} = 0이다.              ----(3)

(I), (II), (III)을 이용하여 다음과 같이
1020x + 790y = gcd(1020, 790)을 만족하는 x, y
를 구해보자.

| gcd             | 1st stage          | 2nd stage                                 | val |
|-----------------|:------------------:|------------------------------------------:|:---:|
| gcd(1020, 790)  | 1020 * x + 790 * y | 1020 * -24 +  790 * (7  - 1020/790 * -24) | 10  |
| gcd(790, 230)   |  790 * x + 230 * y |  790 *   7 +  230 * (-3 -  790/230 * 7)   | 10  |
| gcd(230, 100)   |  230 * x + 100 * y |  230 *  -3 +  100 * (1  -  230/100 * -3)  | 10  |
| gcd(100, 30)    |  100 * x +  30 * y |  100 *   1 +   30 * (0  -   100/30 * 1)   | 10  |
| gcd(30, 10)     |   30 * x +  10 * y |   30 *   0 +   10 * (1  -    30/10 * 0)   | 10  |
| gcd(10, 0)      |   10 * x +   0 * y |   10 *   1 +    0 * 0                     | 10  |
```

# Implementation

* [c++11](a.cpp)


# References

[Basic and Extended Euclidean algorithms @ geeksforgeeks](http://www.geeksforgeeks.org/basic-and-extended-euclidean-algorithms/)
