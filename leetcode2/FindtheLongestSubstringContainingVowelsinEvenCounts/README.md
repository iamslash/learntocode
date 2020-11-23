# Problem

[Find the Longest Substring Containing Vowels in Even Counts](https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/)

# Idea

문자열 `s` 가 주어진다. 모음 `a, e, i, o, u` 가 각각 짝수인
부분문자열들 중 길이가 최대인 것의 길이를 구하는 문제이다.

모음의 개수가 짝수, 홀수를 효율적으로 표현해 보자. 특정 모음에 대해
개수를 저장하지 않아도 된다. 짝수이면 0 홀수이면 1 로 저장해도
충분하다. `XOR` 연산을 사용하면 쉽게 구현할 수 있다.  `int bm` 에
`uoiea` 순서대로 짝수, 홀수 정보를 저장한다. 즉, `a` 가 홀수라면 `bm =
1`, `e` 가 홀수라면 `bm = 2`, `i` 가 홀수라면 `bm = 4`, `ae` 가 각각
홀수라면 `bm = 3` 이다.

예를 들어 `s = "leetcodeisgreat"` 인 경우를 살펴보자.

```
      i
 s: - l e e t c o d e i s g r e a t
bm: 0 0 2 0 0 0 8 81014141414121313
    -----------
```

`int bmIdx[32]` 를 선언하여 `bm` 값이 최초 등장했을 때 인덱스를
저장한다. 모음의 개수가 5 개 이므로 `bm` 의 경우의 수는 `2*2*2*2*2 =
32` 이다. 

이때 `bmIdx[0] = -1` 이다. `eeee` 의 경우 `i = 0` 일 때 부분문자열의
길이는 `i - bmIdx[0] = 1` 이어야 하기 때문이다. 나머지 `bmIdx[i]` 는
모두 `-2` 로 초기화 한다.

최초 등장한 `bmIdx[i]` 를 마지막에 등장한 `bmIdx[i]` 에서 빼면
부분문자열의 개수를 구할 수 있다. `i` 를 처음부터 끝까지 순회하면서
`int ans = 0` 를 업데이트 한다.

모든 반복을 마치면 `ans` 가 곧 답이다.

# Implementation

* [go](a.go)

# Complexity

```
O(N) O(1)
```
