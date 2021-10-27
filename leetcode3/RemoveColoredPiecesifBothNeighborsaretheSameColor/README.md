# Problem

[Remove Colored Pieces if Both Neighbors are the Same Color](https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/)

문자열 `s` 가 주어진다. `s` 는 `A, B` 로만 구성되어 있다. Alice 와 Bob
이 게임을 한다.  서로 한번씩 다음을 수행한다. Alice 가 먼저 시작한다.

* 연속된 같은 문자가 3개 이상일 때 양끝을 제외한 문자를 지울 수 있다.
* 더 이상 지울 문자가 없을 때 그 사람이 패자이다.

Alice 가 이길 수 있는지 검증하라.

# Idea

예를 들어 `s = "AAABABB"` 를 살펴보자.

```
         -
Alice: A A A B A B B
  Bob: A   A B A B B
```

따라서 Bob 이 패자이고 답은 `true` 이다.

`s` 를 구성하는 문자들을 살펴본다. 연속된 3 개이상의 `A` 로 구성된
문자열들 중 지울 수 있는 `A` 의 개수를 구한다. 마찬가지로 연속된 3
개이상의 `ㅠ` 로 구성된 문자열들 중 지울 수 있는 `B` 의 개수를 구한다.
`A` 의 개수가 `B` 의 개수보다 많다면 답은 `true` 이다. 그렇지 않으면
`false` 이다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(N) O(1)
```
