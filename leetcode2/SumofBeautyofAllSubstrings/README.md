# Problem

[Sum of Beauty of All Substrings](https://leetcode.com/problems/sum-of-beauty-of-all-substrings/)

문자열 `s` 가 주어진다. 출현횟수가 가장 많은 문자의 개수와 출현횟수가
가장 적은 문자의 개수의 차이를 `beauty` 라고 하자.  `s` 의 substring
들의 beauty 를 모두 합한 값을 값을 구하라.

# Idea

예를 들어 `s = "aabcb"` 의 경우를 살펴보자.

```
  aab: 2 - 1 = 1
 aabc: 2 - 1 = 1
aabcb: 2 - 1 = 1
 abcb: 2 - 1 = 1
  bcb: 2 - 1 = 1
```

따라서 답은 1 이다.

다음과 같은 변수를 선언한다.

> * `ans`: 답

인덱스 `i` 를 `[0..n)` 동안 순회하면서 다음을 반복한다.
* `freq = [0]*26` 를 선언하여 문자별 출현횟수를 저장한다.
* 인덱스 `j` 를 `[i..n)` 동안 순회하면서 다음을 반복한다.
* `s[i..j]` 의 beauty 를 구하여 `ans` 에 더한다. 즉, `ans +=
  max(freq) - min(x for x in freq if x)` 를 수행한다.

모든 반복을 마치면 `ans` 가 곧 답이다.

# Implementation

* [python3](a.py)

# Complexity

```
O(N^2) O(1)
```
