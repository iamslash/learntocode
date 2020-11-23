# Problem

* [BOARDCOVER2 @ algospot](https://algospot.com/judge/problem/read/BOARDCOVER2)

# Idea

- exhaustive search 로 접근해보자.
- 보드의 가장 위의 왼쪽 부터 한칸씩 탐색하면서 블록을 놓아보자. 블록을 놓을때 주어진 블록을 회전시키면 총 4가지 모양의 블록을 만들어 낼 수 있다. 블록의 모양에 따라 회전을 하더라도 같은 모양이 나올 수 있다.
- 이번에 탐색할 위치에 만들어낸 블록의 가장 위의 왼쪽을 피봇으로 하여
  놓자.
- 앞으로 탐색할 공간의 숫자를 블록이 차지하는 공간의 숫자로 나누면
  최대 놓을 수 있는 블록의 숫자가 계산된다. 지금까지 구한 최적해의
  크기가 앞서 언급한 최대 놓을 수 있는 블록의 숫자가 보다 크다면
  더이상 탐색해 봐야 의미 없으므로 가지치기하자. 이것을 optimistic
  heuristic 혹은 admissible heuristic 이라고 한다. 아무리 많아 봐야
  이것보다는 많아 질수 없다는 의미에서 overestimate heuristic (과대
  평가 휴리스틱)이라고도 한다. 한편 TSP처럼 아무리 적어 봐야
  이것보다는 적어 질 수 없는 경우 underestimate heuristic (과소
  평가 휴리스틱)이라고 한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
```

