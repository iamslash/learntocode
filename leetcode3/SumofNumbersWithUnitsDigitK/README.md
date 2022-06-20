# Problem

[Sum of Numbers With Units Digit K](https://leetcode.com/problems/sum-of-numbers-with-units-digit-k/)

숫자 `num, k` 가 주어진다. 마지막 숫자가 `k` 인 것들을 더해서 합이 `num`
이 되도록 해보자. 그 숫자들의 최소개수를 구하라.

# Idea

예를 들어 `num = 58, k = 9` 의 경우를 살펴보자. 

```
 9
49
```

몇가지 규칙을 발견할 수 있다. 

`num = 0` 이면 볼 것도 없이 답은 `0` 이다.

선택된 숫자들의 마지막 숫자는 `k` 이다. 그리고 그 합의 마지막 숫자
역시 `num` 의 마지막 숫자와 같아야 한다. 즉, 다음과 같은 규칙을
만족하면 `cnt` 가 곧 답이다.

```
k * cnt % 10 == num % 10
```

마지막 숫자만 `k` 가 되고 나머지 숫자는 얼마든지 조작할 수 있다.

따라서 다음과 같이 풀이한다. 

마지막 숫자 `a` 를 `1` 부터 `a * k <= num && a <= 10` 동안 하나씩
증가하면서 다음을 반복한다. 

* `k * a % 10 == num % 10` 이면 `a` 를 리턴한다.

모든 반복을 마치면 답이 없다. `-1` 을 리턴한다.

# Implementation

* [java11](MainApp.java)

# Complexity

```
O(1) O(1)
```
