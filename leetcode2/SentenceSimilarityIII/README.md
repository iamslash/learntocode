# Problem

> [Sentence Similarity III](https://leetcode.com/problems/sentence-similarity-iii/)

문자열 `a, b` 가 주어진다. 두 문자열은 문장의 형태를 띄고 있다. 즉,
영문 대소문자와 공백으로만 구성된다. 둘 중 하나의 문자열에 임의의
문장을 삽입하자. 이때 두 문자열이 같을 수 있는지 검증하는 문제이다.

# Idea

예를 들어 `sentence1 = "My name is Haley", sentence2 = "My Haley"` 
의 경우를 살펴보자.

```
a: My name is Haley
b: My Haley
A: 0 1 2 3
B: 0 3
```

따라서 답은 `true` 이다.

다음과 같은 변수들을 선언한다.

> * `String A[]` 를 선언하여 `a.split(" ")` 를 저장한다.
> * `String B[]` 를 선언하여 `b.split(" ")` 를 저장한다.
> * `int s1 = 0, e1 = A.length - 1`
> * `int s2 = 0, e2 = B.length - 1`

이때 `A.length >= B.length` 가 되도록 한다.

먼저 `A[s1].equals(B[s2])` 동안 `s1, s2` 를 증가한다. 그리고
`A[e1].equals(B[e2])` 동안 `e1, e2` 를 감소한다.

모든 반복을 마치고 `s2 > e2` 이면 `true` 이다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(N) O(1)
```
