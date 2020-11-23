# Problem

[Maximum Score Words Formed by Letters](https://leetcode.com/problems/maximum-score-words-formed-by-letters/)

# Idea

문자열의 모음 `W[]` 와 문자의 모음 `L[]`, 숫자의 모음 `S[]` 가
주어진다.  `L[i]` 를 사용하면 점수는 `S[L[i]-'a']` 이다. `L[]` 를
이용하여 `W[]` 의 문자열들을 만들어 보자. `L[]` 를 모두 사용할 필요는
없다. 가장 높은 점수가 되었을 때 그 점수를 구하는 문제이다.

예를 들어 다음과 같은 경우를 살펴보자.

```
W = ["dog","cat","dad","good"]
L = ["a","a","c","d","d","d","g","o","o"]
S = [1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0]

 dad: 5+1+5
good: 3+2+2+5

 dad: 5+1+5
 dog: 5+2+3
```

`int cnts[26]` 을 선언하여 문자의 개수를 저장한다. 이것은 DFS 의
`visited[]` 와 같다.

다음과 같이 부분문제 `dfs` 를 선언한다.

```
dfs(String[] W, int[] cnts, int[] scores, int i)
     W: words
  cnts: visited of DFS
scores: scores
     i: index of W
```

`dfs` 는 다음과 같이 구현한다.

* `int scoreSkip` 을 선언하여 `W[i]` 를 포함하지 않고 계산한 점수를
저장한다.  
* `int scoreInclude` 를 선언하여 `W[i]` 를 포함하여 계산한
점수를 저장한다. 이때 주어진 `cnts` 로 `W[i]` 를 구성할 수 없다면
`scoreInclude = 0` 이다.
* `scoreSkip` 과 `scoreInclude` 를 비교하여 최대값을 리턴한다.

# Implementation

* [java8](Solution.java)

# Complexity

```
O(W^2S) O(W), S: max(W[i])
```
