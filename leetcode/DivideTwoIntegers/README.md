# Problem

[Divide Two Integers @ leetcode](https://leetcode.com/problems/divide-two-integers/description/)

두 정수 `a` 와 `b` 가 있다고 할 때 `a` 를 `b` 로 나눈 몫 `q` 을 `*, /`
연산자를 사용하지 않고 구해보자.

# Idea

가장 먼저 다음과 같이 `a` 에서 `b` 를 하나씩 제거하면서 `q` 를 하나씩
늘려 볼 수 있다. 그러나 시간 복잡도가 높기 때문에 효율적이지 못하다.

```
while (a >= b) {
    a -= b;
    q++;
}
```

다음과 같이 `a` 에서 `b` 를 적당히 키워가며 제거하면 시간 복잡도를
낯울 수 있기 때문에 효율적이다. 이때 `q` 역시 `b` 가 키워진 만큼
늘려야 한다. 적당히 라는 표현은 2의 배수를 곱한 것과 같은 의미이다.

```
r = 0;
while (a >= b) {
    c = b;
    q = 1;
    while (a >= c) {
        a -= c;
        r += q;
        c <<= 1;
        q <<= 1;
    }
}
```

`a`, `b` 의 범위가 `[-2^32, 2^32-1]` 이기 때문에 overflow 를 유의해서
구현해야 한다.

# Implementation

[c++11](a.cpp)

# Complexity

```
O(lgN) O(1)
```
