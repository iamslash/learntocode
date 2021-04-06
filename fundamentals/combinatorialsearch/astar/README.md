# Abstract

A* 를 구현해본다.

# References

* [A* @ geeksforgeeks](https://www.geeksforgeeks.org/a-search-algorithm/)
* [A* @ youtube](https://www.youtube.com/watch?v=vP5TkF0xJgI)

# keywrod

```cpp
openset, closeset
f, g, h
```

# Idea

시작점을 `(ys, xs)` 라 하고 종료점을 `(yd, xd)` 라고 하자.

앞으로 방문할 노드들을 `openset` 에 저장하고
이미 방문한 노드들을 `closeset` 에 저장한다.

각 노드마다 `f, g, h` 를 계산한다.

* `g` : 시작점에서 노드까지의 거리
* `h` : 노드에서 종료점까지의 예상거리. 대충 때려 맞춘다. `manhattan
  distance, diagonal distance, euclidean distance` 등등 다양한
  휴리스틱이 존재한다.
* `f` : `g` 와 `h` 의 합이다.

`(ys, xs)` 부터 시작하여 다음을 반복한다.

* `openset` 에서 노드를 하나 가져오고 이미 방문하였으므로 그 노드를
  `closeset` 에 삽입한다.  그리고 그것의 좌표를 `(yn, xn)` 이라고
  하자. 만약 이것이 `(yd, xd)` 와 같다면 이미 답을 찾은 것이다. 이것은
  `openset` 의 노드들 중 가장 `f` 가 작다. 이번에 방문할 만 하다.
* `(yn, xn)` 의 이웃들을 방문시도해 본다. 다음번에 방문할 만하면
  `openset` 에 삽입한다.

# Implementation

* [c++11](a.cpp)
  