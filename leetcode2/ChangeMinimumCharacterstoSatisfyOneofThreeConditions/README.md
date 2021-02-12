# Problem

[Change Minimum Characters to Satisfy One of Three Conditions](https://leetcode.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/)

문자열 `a, b` 가 주어진다. 한번의 operation 으로 `a` 혹은 `b` 의
한 문자를 임의의 문자로 바꿀 수 있다.

다음과 같은 3 가지 조건 중 하나를 만족하도록 operation 을 수행해 보자.

* `a` 의 모든 문자가 `b` 의 모든 문자보다 작다.
* `b` 의 모든 문자가 `a` 의 모든 문자보다 작다.
* `a, b` 는 하나의 문자로 구성된다.

최소 operation 을 구하라.

# Idea

예를 들어 `a = "aba", b = "caa"` 를 살펴보자.

`int[] aFreq = new int[26], bFreq = new int[26]` 을 선언하여 `a, b`
문자의 출현 횟수를 저장한다. `int ans = a.length() + b.length()` 을
선언하여 답을 저장한다.

```
    a: a b a
    b: c a a

aFreq: a b
       2 1
bFreq: a c
       2 1
```

인덱스 `i` 를 `[0..26)` 만큼 순회하며 다음을 반복한다.

* 조건 3 을 구한다. 즉, `ans = min(ans, a.length() - aFreq[i] +
  b.length() - bFreq[i])` 를 수행한다.
* `i > 0` 이면 `aFreq[i] += aFreq[i-1], bFreq[i] += bFreq[i-1]` 를
  수행한다.
* `i < 25` 이면 
  * 조건 1 를 구한다. `a` 의 일부를 교체하고 `b` 의 일부를 교체할
    숫자를 구한다. 즉, `ans = min(ans, a.length() - aFreq[i] +
    bFreq[i])` 를 수행한다.
  * 조건 2 를 구한다. `a` 의 일부를 교체하고 `b` 의 일부를 교체할
    숫자를 구한다. 즉, `ans = min(ans, b.length() - bFreq[i] + aFreq[i])` 를
    수행한다.
* `i == 25` 이면 `a` 혹은 `b` 문자열은 비어 있게 된다. 고려할 필요가 없다.

모든 반복을 마치면 `ans` 가 곧 답이다.

# Implementation

* [java8](Solution.java)

# Complexity

```
O(N) O(1)
```
