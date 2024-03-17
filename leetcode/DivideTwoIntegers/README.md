# Problem

[Divide Two Integers](https://leetcode.com/problems/divide-two-integers/description/)

두 정수 `dividend` 와 `divisor` 가 있다고 할 때 `dividend` 를 `divisor` 로 나눈 몫 `q` 을 `*, /` 연산자를 사용하지 않고 구해보자.

# Idea

다음과 같은 경우 overflow 가 발생할 수 있다. 특별히 처리하자.

```
overflow happens !!!

-2,147,483,648 / -1 = 2,147,483,648

32bit interger is between -2,147,483,648 and 2,147,483,647
```

가장 먼저 다음과 같이 `dividend` 에서 `divisor` 를 하나씩 제거하면서 `q` 를 하나씩
늘려 볼 수 있다. 그러나 시간 복잡도가 높기 때문에 효율적이지 못하다.

```
ant = 0
while (dividend >= divisor) {
    dividend -= divisor;
    ans++;
}
```

다음과 같이 `dividend` 에서 `divisor` 를 적당히 키워가며 제거하면 시간 복잡도를
낯출 수 있기 때문에 효율적이다. 이때 `q` 역시 `divisor` 가 키워진 만큼
늘려야 한다. 적당히 라는 표현은 `2` 의 배수를 곱한 것과 같은 의미이다.

```
ant = 0;
while (dividend >= divisor) {
    tmpDivisor = divisor;
    cnt = 1;
    while (dividend - (tmpDivisor << 1) >= 0) {
        tmpDivisor <<= 1;
        cnt <<= 1;
    }
    dividend -= tmpDivisor
    ans += cnt
}
```

# Implementation

- [c++11](a.cpp)
- [java](MainApp.java)

# Complexity

```
O(lgN) O(1)
```
