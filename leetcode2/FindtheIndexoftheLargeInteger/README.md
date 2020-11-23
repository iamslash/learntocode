# Problem

[Find the Index of the Large Integer](https://leetcode.com/problems/find-the-index-of-the-large-integer/)

`reader *ArrayReader` 가 주어진다. 하나를 제외하고 모두 같은 숫자들이
배열에 존재한다. 그 하나는 다른 수 보다 크다. 그 수를 찾아라.

# Idea

`reader.length(), reader.compareSub()` 를 이용해서 [binary
search](/fundamentals/search/binarysearch/README.md) 로 해결할 만
하다. 

먼저 `lo, mi, hi` 를 선언하여 [binary
search](/fundamentals/search/binarysearch/README.md) index 로
활용한다.

이때 한가지 주의 사항이 있다. 일정 구간의 숫자 합을
`reader.compareSub()` 로 구해야 하므로 `[lo..hi]` 의 개수가 짝수이면
`r = reader.compareSub(lo,mi,mi+1,hi)` 를 이용한다. `[lo..hi]` 의
개수가 홀수이면 `r = reader.compareSub(lo,mi,mi,hi)` 를 이용한다.

가운데 부분이 겹치기 때문에 `r <= 0` 일 때에는 `hi = mi` 를 수행한다.
만약 `r == 1` 이면 `lo = mi + 1` 을 수행한다.

# Implementation

* [go](a.go)

# Complexity

```
O(lgN) O(1)
```
