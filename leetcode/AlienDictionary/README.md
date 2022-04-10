# Problem

[Alien Dictionary](https://leetcode.com/problems/alien-dictionary/)

문자열의 모음 `words[]` 가 주어진다. 영문 소문자를 사용하는 외계어가
있다고 해보자.  `words[i]` 는 `words[i+1]` 보다 사전순으로 앞에 온다.
외계어가 사용하는 문자들의 사전순서를 구해보자.

# Idea

입력값으로 순서가 주어진다. 그리고 사전순서를 구해야
한다. [topological
sort](/fundamentals/graph/topologicalsort/README.md) 로 해결할 만
하다. Queue 를 사용하는 방법이 더욱 수월하다.

다음과 같은 변수들이 필요하다.

```
int[][] graph = new int[26][26]
Map<Integer, Integer> indegMap = new HashMap<>()
Queue<Integer> queue = new LinkedList<>();
StringBuilder order = new StringBuilder()
```

그리고 다음과 같은 구조로 구현한다.

```
Build indegMap
Build graph
Build queue
```

다음과 같은 사항을 주의하자.

첫 번째 다른 문자끼리만 위상차이가 있다. 그 이후는 비교할 필요가 없다.
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

모든 반복을 마치고 `order.length() != indegMap.size()` 이면
cycle 이 존재한다? 빈문자열을 리턴한다.

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

# Complexity

```
O(N^2) O(N^2)
```
