# Problem

[Replace the Substring for Balanced String](https://leetcode.com/problems/replace-the-substring-for-balanced-string/)

# Idea

`Q, W, E, R` 로 구성된 문자열 `s` 가 주어진다. 각 문자가 동일한 개수를
갖게 되면 균형이 잡혔다고 한다. 균형잡힌 문자열을 만들기 위해 연속된
부분문자열을 골라보자. 그 중 길이가 가장 작은 녀석의 개수를 구하는
문제이다.

4 개의 동일한 개수를 갖어야 한다. 이때 그 개수를 `k = len(s) / 4` 에
저장하자.  `var cnts map[byte]int` 를 선언하여 `Q, W, E, R` 의 개수를
저장하자. 인덱스 `i, j` 를 이용하여 sliding window 한다.

각 문자의 개수가 모두 `k` 보다 작거나 같은 구간들을 `r` 이라 하자. `r`
의 문자들을 저절히 교체하면 `s` 는 균형이 잡히게 된다. `r` 의 후보들중
가장 길이가 작은 녀석이 답이다.

예를 들어 다음과 같이 `s = QQWE` 를 살펴보자.

```
_        _
QQWE    QQWE
```

`r` 의 후보는 첫번째 Q 와 두번째 Q 이다. 즉, Q 를 R 로 교체하면 `s` 는 균형이 잡히게 된다.

이번에는 `s = WWEQERQWQWWRWWERQWEQ` 를 살펴보자. 다음과 같이 `r` 의 후보들을 생각해 볼 수 있다.

```
 i                        i                        i
 WWEQERQWQWWRWWERQWEQ    WWEQERQWQWWRWWERQWEQ    WWEQERQWQWWRWWERQWEQ
         j                       j                       j

 cnts: Q W E R           cnts: Q W E R           cnts: Q W E R           
       5 2 2 2                 5 3 2 2                 5 4 2 2
    k: 5                    k: 5                    k: 5
    r: 9                    r: 8                    r: 7

    i                         i                        i
 WWEQERQWQWWRWWERQWEQ    WWEQERQWQWWRWWERQWEQ    WWEQERQWQWWRWWERQWEQ
         j                        j                       j

 cnts: Q W E R           cnts: Q W E R           cnts: Q W E R           
       5 4 3 2                 5 4 3 3                 5 4 3 4
    k: 5                    k: 5                    k: 5
    r: 6                    r: 5                    r: 4
```

`r` 의 후보들중 가장 작은 길이는 4 이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
