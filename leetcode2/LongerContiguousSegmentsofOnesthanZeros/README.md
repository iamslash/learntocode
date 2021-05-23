# Problem

[Longer Contiguous Segments of Ones than Zeros](https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/)

문자열 `s` 가 주어진다. `s` 는 `0, 1` 로 구성되어 있다. 연속된 `1`
의 최대 개수가 연속된 `0` 의 최대 개수보다 더욱 큰 값인지 검증하라.

# Idea

예를 들어 `s = "1101"` 의 경우를 살펴보자. 

```
                           s: 1 1 0 1
max continuous count of zero: 1
 max continuous count of one: 2
```

따라서 답은 `true` 이다.

다음과 같은 변수들을 선언하여 linear traversal 한다.

* `maxZeroCnt`: max continuous count of zero
* `maxOneCnt`: max continuous count of one
* `conZeroCnt`: continuous count of zero
* `conOneCnt`: continuous count of one

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(N) O(1)
```
