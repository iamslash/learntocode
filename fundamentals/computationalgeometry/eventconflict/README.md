# Problem

수열 `evt1[], evt2[]` 가 주어진다. `evt1[0], evt1[1]` 은 `evt1` 의 시작과
끝이다. `evt2[0], evt2[1]` 은 `evt2` 의 시작과 끝이다. 두 event 가 충돌하는지
검증하라.

# Idea

다음과 evt1, evt2 가 겹치는 경우는 다음과 같다.

```
evt1: ----
evt2:   ----

evt1:   ----
evt2: ----

evt1: ------
evt2:  ----

evt1:  ----
evt2: ------
```

다음과 같은 equation 을 만들 수 있다.

```c
evt1[0] <= evt2[1] && evt2[0] < evt1[1]
```

# References

* [Determine if Two Events Have Conflict](https://leetcode.com/problems/determine-if-two-events-have-conflict/)
