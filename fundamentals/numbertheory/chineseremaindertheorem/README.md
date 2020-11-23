# Abstract

중국인 나머지 정리에 대해 적는다.

# Idea

중국인 나머지 정리의 정의는 다음과 같다.

```
두 양의 정수 m_{1}, m_{2}이 서로소 일때
임의의 두 정수 c_{1}, c_{2}에 대해 연립일차합동방정식
x ≡ c_{1} (mod m_{1})
x ≡ c_{2} (mod m_{2})
는 법 m_{1}, m_{2}에 관하여 단 한개의 해
x ≡ u (mod m1m2)를 갖는다.

x = m_{1} * m_{2} * k + u 이기 때문에
u는 하나 이지만 x는 여러개다.
```

위의 정리를 이용해서 다음과 같은 문제들을 해결 할 수 있다.

```
5로 나누어 나머지가 1이고 7로 나누어 나머지가 3인 수는?
3으로 나누어 나머지가 2, 4로 나누어 나머지가 3, 5로 나누어 나머지가 1인 수는?
```

직관적으로 이해하기 위해 앞서 언급한 문제를 다음과 같이 
해결해 보자.

```
5로 나누어 나머지가 1이고 7로 나누어 나머지가 3인 수는?

x % 5 = 1
x % 7 = 3

x는 31, 66, 101, ...이다.

5 * 7 = 35
x = 31 + 35 * m

3으로 나누어 나머지가 2, 4로 나누어 나머지가 3, 5로 나누어 나머지가 1인 수는?

x % 3 = 2
x % 4 = 3
x % 5 = 1

x는 11, 71, 131, ...이다.

3 * 4 * 5 = 60
x = 11 + 60 * m
```

x를 구하기 위해 무식한 방법(brute force),
나머지 곱셈의 역원(modular multiplicative inverse)을 이용한 방법
등이 있다.

# 무식한 방법 (brute force)

[CRT @ geeksforgeeks](http://www.geeksforgeeks.org/chinese-remainder-theorem-set-1-introduction/)

```cpp
#include <cstdio>

int solve(int num[], int rem[], int k) {
  int r = 1;
  while (true) {
    int j;
    for (j = 0; j < k; ++j) {
      if (r % num[j] != rem[j])
        break;
    }
    if (j == k)
      return r;
    ++r;
  }
  return r;
}

int main() {
  int num[] = {3, 4, 5};
  int rem[] = {2, 3, 1};
  int k = ;
  printf("%d\n", sizeof(num) / sizeof(num[0]));
  printf("%d\n", solve(num, rem, k));
  return 0;
}
```

# 나머지 곱셈의 역원(modular multiplicative inverse)을 이용한 방법

[중국인의 나머지 정리 @ 나무위키](https://namu.wiki/w/%EC%A4%91%EA%B5%AD%EC%9D%B8%EC%9D%98%20%EB%82%98%EB%A8%B8%EC%A7%80%20%EC%A0%95%EB%A6%AC)
[CRT @ geeksforgeeks](http://www.geeksforgeeks.org/chinese-remainder-theorem-set-2-implementation/)

중국인 나머지 정리의 존재성 증명을 잘 살펴보면 나머지 곱셈의 역원을
이용해서 x를 구하는 방법을 알 수 있다.

```
m_{k}로 나누면 나머지가 a_{k}인 어떤 수 x를
구해보자. (1 <= k <= n)

m = m_{1} * m_{2} * ... * m_{n} 라고 하자.
이때 m_{k}들은 임의 쌍에 대해 서로소 이다.
v_{k} = m / m_{k} 라고 하자. v_{k}는 m에서 m_{k}를 제거한 것이다.

임의의 정수 k에 대해 v_{k} 와 m_{k}는 서로소이기 때문에
gcd(v_{k}, m_{k}) = 1 이다.

베주의 항등식에 의해 
v_{k} * s_{k} + m_{k} * t_{k} = 1 를
만족하는 정수 s_{k}, t_{k}가 존재한다.
(ax + by = 1의 형태이다.)
t_{k}는 사용하지 않을 테니 관심 없다.

이것을 합동식으로 고쳐 보자.
v_{k} * s_{k} ≡ 1 (mod m_{k})                   -----(1)

이제 x를 다음과 같이 표현할 수 있다.
x         =  a_{1}*v_{1}*s_{1} + a_{2}*v_{2}*s_{2} + ... + a_{n}*v_{n}*s_{n}

양변을 m_{k}로 나눈 나머지를 계산해 보자.
x % m_{k} = (a_{1}*v_{1}*s_{1} + a_{2}*v_{2}*s_{2} + ... + a_{n}*v_{n}*s_{n}) % m_{k}
          = a_{1}*v_{1}*s_{1}%m_{1} + a_{2}*v_{2}*s_{2}%m_{2} 
            + ... + a_{n}*v_{n}*s_{n}%m_{n}     -----(2)

우변의 k를 제외한 항들은 0이 될 것이다.
j != k 이면 v_{j} % m_{k} = 0 이기 때문이다. 
v_{j}의 정의를 다시 생각해 보자. 
v_{j} 에 m_{j}는 이미 나누어져 제거 되었다.
즉 m_{k} 는 v_{j}의 약수이다.

따라서 

x % m_{k} = a_{k}*s_{k}*v_{k} % m_{k}
          = a_{k} * 1 (식 (1))
x ≡ a_{k} (mod m_{k})

결국 x는 주어진 연립 합동식의 한 해이고
이것을 중국인 나머지의 존재성 증명이라고 한다.

식(1)에 의해 s_{k}는 v_{k}의 나머지 곱셈의 역원
(modular multiplicative inverse)이다.
s_{k}는 페르마의 소정리 혹은 확장 유클리드 알고리즘으로
구할 수 있다.

그렇다면 식(2)를 이용해서 x를 구할 수 있다.

mod[] = {3, 4, 5}    // modular : m_{k}
rem[] = {2, 3, 1}    // remainder : a_{k}
prd   = 60           // product : m
pbi[] = {20, 15, 12} // product but i : v_{k}
inv[] = {2,   3,  3} // modular multiplicative inverse of i : s_{k}
  (20 * 2) % 3 = 1
  (15 * 3) % 4 = 1
  (12 * 3) % 4 = 1
  
x % m_{k} = (rem[0]*pbi[0]*inv[0] +
             rem[1]*pbi[1]*inv[1] +
             rem[2]*pbi[2]*inv[2]) % 60
          = (2 * 20 * 2 +
             3 * 15 * 3 +
             1 * 12 * 3) % 60
          = (40 + 135 + 36) % 60
          = 11
따라서 x = 11 + prd * k (0 <= k)
```

## Implementation

* [c++11](a.cpp)