# Problem

[Word Ladder](https://leetcode.com/problems/word-ladder/)

문자열 `beg, end`, 문자열의 모음 `wordList` 가 주어진다. `beg` 부터 한
문자를 교체하자. 그리고 그 문자는 `wordList` 에 존재해야 한다.  `end`
는 반드시 `wordList` 에 존재한다. `beg` 로 부터 시작하여 `end` 로
변환해 보자. 가장 최소 길이를 구하라.

# Idea

예를 들어` beginWord = "hit", endWord = "cog", wordList =
["hot","dot","dog","lot","log","cog"]` 의 경우를 살펴보자.

```
hit -> hot -> dot -> dog -> cog
```

따라서 답은 5 이다.

`Map<String, Integer> visitMap` 를 선언하여 변환된 단어와 `beg` 로
부터의 변환된 거리를 저장하자. `wordList` 의 단어들을 거리값을 0 으로
하여 저장한다.  `beg` 로 부터 변환한 임의의 단어를 `mid` 라고 한다면
`mid` 는 반드시 `visitMap` 에 존재해야 한다. 그 거리가 0 보다 크다면
이미 beg 로 부터 변환되었다는 것을 의미한다. 이미 방문 했으므로 다시
`mid` 로 부터 변환할 이유가 없다.

`Queue<Pair> q` 를 선언하여 bfs queue 로 이용한다. queue 에서 빼낸
단어를 `uWord`, 거리를 `uDist` 라고 하자. `uWord` 가 `endWord` 와
같다면 `uDist` 가 곧 답이다.

Pair 는 다음과 같이 선언한다.

```java
class Pair {
  String word;
  Integer dist;
  public Pair(word, dist) {
    this.word = word;
    this.dist = dist;
  }
}
```

`uWord` 를 한문자씩 이동하면서 다른 문자로 교체한다. 그리고 교체된
문자를 `vWord` 라고 하자. `vDist` 에 `uDist + 1` 를 저장한다. `vWord`
는 반드시 `visitMap` 에 존재해야 한다. 그리고 그 거리가 0 보다 크다면
이미 방문했으므로 다시 방문할 이유가 없다.  건너뛴다. 그렇지 않다면
`q` 에 `new Pair(vWord, vDist)` 를 삽입하고 `visitMap.put(vWord,
vDist)` 를 삽입한다.

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

# Complexity

```
O(N) O(N)
```
