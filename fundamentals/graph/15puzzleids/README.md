# Abstract

0 부터 15 까지 숫자가 배치된 퍼즐을 생각한다. 
0 은 빈칸을 의미한다.
0 은 상하좌우 4 방향으로 움직일 수 있다. 0 이 움직이면 0 보다 큰 숫자와 교체된다.
0 이 움직일때마다 퍼즐의 상태가 변경된다. 

# Problem

퍼즐의 상태를 나타낸 일차원 배열 `src[16]` 와 `dst[16]` 이 주어진다. `src[16]` 에서 `dst[16]` 으로 상태를 변경할 때 최소 이동수를 구하는 문제이다.

# Keyword

```cpp
State, get_adj, operator<, operator==, bitmask, move, get, set, swap, get_zero_idx, best, dfs, ids
```    

# Idea

uint64_t 는 64 비트 이므로 4 비트씩 16 그룹으로 퍼즐의 상태를 표현 할 수 있다. 퍼즐의 상태를 `state space` 라고 한다. `src state space` 에서 `dst state space` 로 `bfs` 탐색을 하여 거리를 계산하면 `15 puzzle` 문제를 해결 할 수 있다.


BFS 는 space complexity 가 너무 크다. DFS 를 이용하면 space complexity 를 줄일 수 있다. 하지만 DFS 는 깊이 우선으로 탐색 하기 때문에 탐색 범위를 점점 넓혀 가면서 탐색 할 필요가 있다. `dst state space` 가 탐색 공간 중간에 있다면 효율적이다. 탐색 범위를 점점 넓혀 간다고 해서 iteratively deep searching 이라고 한다.
  
limit 를 늘려가면서 DFS 를 수행한다. 탐색 범위를 넓히는 것이다. best 를 설정하여 best 가 limit 보다 작거나 같으면 종료한다.

# Implementation

* [c++11](a.cpp)
