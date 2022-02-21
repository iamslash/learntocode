# Problem

[Count Integers With Even Digit Sum](https://leetcode.com/problems/count-integers-with-even-digit-sum/)

숫자 `num` 이 주어진다. `nums` 보다 작거나 같은 자연수들 중 각
자리수의 합이 짝수인 숫자의 개수를 구하라.

# Idea

예를 들어 `num = 4` 의 경우를 살펴보자.

```
1
2 - o
3
4 - o
```

따라서 답은 `2` 이다.

다음과 같이 `10, 20, 30` 의 경우를 살펴보자.

```
10 = 2, 4, 6, 8 (4개)
20 = 2, 4, 6, 8, 11, 13, 15, 17, 19, 20 (10개)
30 = 2, 4, 6, 8, 11, 13, 15, 17, 19, 20, 22, 24, 26, 28 (14개)
```

다음과 같은 규칙을 발견할 수 있다.

```
sum is sum of digits of num

when sum is even: num / 2
 when sum is odd: (num - 1) / 2
```

다음과 같이 규칙을 더욱 간단히 할 수도 있다.

```
(num - sum % 2) / 2
```

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(log_10_N) O(1)
```
