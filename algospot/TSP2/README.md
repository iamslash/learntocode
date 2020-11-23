- [Abstract](#abstract)
- [References](#references)
- [backtracking](#backtracking)
  - [Idea](#idea)
  - [Implementation](#implementation)
- [simple pruning](#simple-pruning)
  - [Idea](#idea-1)
  - [Implementation](#implementation-1)
- [simple heuristic pruning](#simple-heuristic-pruning)
  - [Idea](#idea-2)
  - [Implementation](#implementation-2)
- [greedy](#greedy)
  - [Idea](#idea-3)
  - [Implementation](#implementation-3)
- [swapping past paths pruning](#swapping-past-paths-pruning)
  - [Idea](#idea-4)
  - [Implementation](#implementation-4)
- [MST heuristic pruning](#mst-heuristic-pruning)
  - [Idea](#idea-5)
  - [Implementation](#implementation-5)
- [partial dynamic programming](#partial-dynamic-programming)
  - [Idea](#idea-6)
  - [Implementation](#implementation-6)

-----

# Abstract

* TSP (Traveling salesman problem) 를 해결하는 여러가지 전략들을 효율적인 순서대로 적어본다.
* 실제로 TSP 를 해결하기 위해서는 Integer Programming (정수계획법) 을 주로 사용한다. Integer Programming 은 최적화 이론에서 유명한 문제인 Linear Programming (선형계획법) 의 일종으로 다항시간에 푸는 알고리즘은 아직 없다. [Solution of a Large-Scale Traveling-Salesman
Problem](https://www.rand.org/content/dam/rand/pubs/papers/2014/P510.pdf) 에 의하면 1954 년 Integer Programming 을 이용해 49 개 도시에 대해 TSP 를 풀어냈다. 

# References

- [Georgia Tech's TSP](http://www.tsp.gatech.edu/)
  - TSP 해결 프로그램중 가장 강력한 Concorde 의 소스코드와 각종 기법들이 소개되어 있다. Concorde 는 1000 개의 도시를 갖는 입력을 10 분만에 풀어낸다.

# backtracking

## Idea

- 현재 탐색하는 search space 를 탐색하고 그 이전 search space 로 되돌아가서 새로운 search space 를 탐색하자.

## Implementation

- [c++11](a_backtracking.cpp)

# simple pruning

## Idea

- 지금까지 구한 거리가 이미 최적해보다 크거나 같다면 더이상 search
  space를 탐색할 필요가 없다.

```cpp
  // pruning
  if (BEST <= past_dist)
    return;
```

## Implementation

- [c++11](a_simple-pruning.cpp)

# simple heuristic pruning

## Idea

- heuristic 의 범위를 최대한 줄여서 하는 것을 underestimate
  heuristic 혹은 optimistic heuristic 이라고 한다. heuristic 의 범위를 0으로 하면 극단적으로 좁혀지긴 하지만 heuristic 의 대상이 없기 때문에
  가지치기가 되지 않아서 효과가 없다. 그렇다고 heuristic 의 범위를 너무 넓게 하면 최적해 마저 가지치기가 될 수 있다.
- 아직 방문하지 않은 도시들에 대해 인접한 간선중 가장 짧은 간선들의
  합과 지금까지의 거리를 더한 것이 최적해 보다 크다면 가지치기
  하자. 아직 방문하지 않은 도시를 방문 하려면 인접한 간선 중 하나를
  지나가야 하므로 이들 중 가장 짧은 간선들의 길이만을 모으면 최단 경로 이하의 값이 될 수 밖에 없다.

## Implementation

- [c++11](a_simple-heuristic-pruning.cpp)

# greedy

## Idea

- 가장 가까운 장소부터 탐색하자.

## Implementation

- [c++11](a_greedy.cpp)

# swapping past paths pruning

## Idea

- 지금까지 지나온 경로들중에 순서를 바꿔주면 경로가 짧아지는 경우가 있다면 더이상 탐색해봐야 의미가 없으므로 가지치기 한다. 예를 들어 `p-a-b-q` 와 같은 순서로 노드들을 탐색했다고 해보자. 앞의 탐색순서를 `p-b-a-q` 로 하여 거리를 계산했더니 `p-a-b-q` 보다 거리가 짧아졌다면 더이상 탐색해봐야 최적의 경로가 되지 못하기 때문에 가지치기한다.
  
## Implementation

- [c++11](a_swapping-past-paths-pruning.cpp)

# MST heuristic pruning

## Idea

- 현재까지 방문한 거리와 앞으로 방문할 노드들의 MST (minimum spanning tree) 의 거리를 더한 값이 지금까지 최적해 보다 크거나 같다면 가지치기 하자.

## Implementation

- [c++11](a_mst-heuristic-pruning.cpp)

# partial dynamic programming

## Idea

- 앞으로 방문할 노드의 개수가 일정 개수 이하이면 dynamic programming 을 적용하자.
- 부분적으로 dynamic programming 을 수행하기 때문에 space 를 절약할 수 있다. 결국 dynamic programming 이 제일 빠르다.

## Implementation

- [c++11](a_partial-dynamic-programming.cpp)