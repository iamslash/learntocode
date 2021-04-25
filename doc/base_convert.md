# Abstract

진법을 변환하는 전략을 base convert 라고 하자.

예를 들어 10 진수 34(n) 를 2(k) 진수로 변환하는 과정을 살펴보자. 몫을 `q` 라 하고
나머지를 `r` 이라 하자.

```
n: 34
k:  6

q: 34 5 0 
r:    4 5
```

`r` 의 숫자들을 거꾸로 취한 값 `54` 가 곧 답이다.

이것을 코드로 작성하는 것은 까다롭다. 다음과 같이 정리해 본다. `digit` 은 모아서
뒤집어야 답이된다.

```java
while (n > 0) {
  int digit = n % k;
  n /= k;
}
```

# Examples

* [L](/leetcode2/SumofDigitsinBaseK) | [Sum of Digits in Base K](https://leetcode.com/problems/sum-of-digits-in-base-k/)
  