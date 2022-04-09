# Problem

[Alien Dictionary](https://leetcode.com/problems/alien-dictionary/)

문자열의 모음 `words[]` 가 주어진다. 영문 소문자를 사용하는 외계어가
있다고 해보자.  `words[i]` 는 `words[i+1]` 보다 사전순으로 앞에 온다.
외계어가 사용하는 문자들의 사전순서를 구해보자.

# Idea

입력값으로 순서가 주어진다. 그리고 사전순서를 구해야
한다. [topological
sort](/fundamentals/graph/topologicalsort/README.md) 로 해결할 만
하다.

예를 들어 `words[i-1] == "ett", words[i] == "efkt"` 라고 해보자.
이다. 두 문자열에서 얻을 수 있는 순서는 `t < f` 뿐이다.

```
ett
eftt

t < f
```

또한 다음과 같이 `words[i-1]` 의 길이가 `words[i]` 보다 크면서 `words[i-1]`
가 `words[i]` 로 시작된다면 입력값은 제대로 되었다고 할 수 없다.  ""
를 리턴하자.

```
words[i-1]: a b c
  words[i]: a b
```

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

# Complexity

```
O(N^2) O(N^2)
```
