# Problem

[Synonymous Sentences](https://leetcode.com/problems/synonymous-sentences/)

# Idea

두 단어의 모음 `S[][]` 과 하나의 문장 `t` 가 주어진다. `S[i][0], S[i][1]` 은 
서로 비슷한 단어이기 때문에 `t` 에서 서로 바꾸어 사용할 수 있다. 비슷한 단어끼리 바꾸어
사용할 때 가능한 문장들의 모음을 구하는 문제이다.

`S[][]` 를 처음부터 끝까지 순회하면서 `G[][]` 를 완성한다. 이제 `t` 
를 단어들의 모음으로 나눈 것을 `T[]` 라 하자. `T[]` 를 backtracking 하면
가능한 문장들의 모음을 구할 수 있다.

# Implementation

* [go](a.go)

# Complexity

```
???
```
