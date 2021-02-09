# Problem

[Generate Parentheses](https://leetcode.com/problems/generate-parentheses/)

숫자 `n` 이 주어진다. `(`, `)` 를 `n` 개 사용하여 만들 수 있는 valid
parenthese 의 개수를 모두 구하라.

# Idea

예를 들어 `n = 1` 인 경우를 살펴보자.

```
()
```

예를 들어 `n = 2` 인 경우를 살펴보자.

```
(())
()()
```

예를 들어 `n = 3` 인 경우를 살펴보자.

```
((()))
(()())
(())()
()(())
()()()
```

다음과 같은 부분문제 `dfs` 를 구상해 보자.

```
void dfs(ans, leftCnt, ingCnt)

    ans: the answer
leftCnt: the count of left pairs
 ingCnt: the count of unresolved pairs
```

# Implementation

* [c++11](a.cpp)
* [java8](Solution.java)

# Complexity

```
O(2^N) O(N)
```
