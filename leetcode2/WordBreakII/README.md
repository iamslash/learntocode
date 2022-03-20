# Problem

[Word Break II](https://leetcode.com/problems/word-break-ii/)

문자열 `s`, 문자열의 모음 `wordDict[]` 가 주어진다.  `s` 를
`wordDict[]` 의 단어들로 구분할 수 있는 문자열들을 구하라. `s` 는
`wordDict[]` 의 단어들과 공백으로 구성되야 한다.

# Idea

예를 들어 `s = "catsanddog", wordDict =
["cat","cats","and","sand","dog"]` 의 경우를 살펴보자.

```
       s: catsanddog
wordDist: cat cats and sand dog

          cat sand dog
          cats and dog
```

따라서 답은 `["cats and dog","cat sand dog"]` 이다.

전부다 시도해 보고 답을 모으자. [backtracking](/doc/backtracking.md) 으로
해결할 만 하다.

다음과 같은 자료구조를 선언한다.

* `List<String> ans = new ArrayList<>();`: 답을 저장한다.
* `List<String> cand = new ArrayList<>();`: 후보를 저장한다.

다음과 같은 부분문제 `dfs` 를 선언한다.

```
void dfs(s, wordDict, ans, cand, beg)

       s: input
wordDict: input
     ans: 답
    cand: wordDict 의 단어들로 구성된 후보
     beg: 이번에 따져볼 s 의 index
```

그리고 `dfs` 를 다음과 같이 구현한다. 

* `beg == s.length()` 이면 지금까지 찾은 `cand` 가 답이다. `cand` 를
  `ans` 에 추가하고 탐색을 중지한다.
* `s` 를 인덱스 `i` 로 `[beg..n]` 동안 순회하며 다음을 반복한다.
  * `s.substring(beg, i)` 가 `wordDict` 에 없다면 건너뛴다.
  * `s.substring(beg, i)` 가 `wordDict` 에 있다면 그 부분문자열을
    `cand` 에 추가한다. 그리고 `dfs(s, wordDict, ans, cand, i)` 를 호출한다.
  * `cand` 에 추가한 마지막 문자열을 제거하라.  

모든 반복을 마치면 `ans` 가 곧 답이다.

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

# Complexity

```
O(2^N) O(N)
```
