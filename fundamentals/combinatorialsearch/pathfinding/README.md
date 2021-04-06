# Abstract

* 길 찾기 문제를 해결할 수 있는 전략들에 대해 적는다.

# one src to one dst

* [A* @ learntocode](/fundamentals/combinatorialsearch/astar/README.md)
* [Dijkstra algorithm @ learntocode](/fundamentals/graph/dijkstra/README.md) (non-negative weighted graphs)
  * `dist[]` 대신 `src` 에서 `dst` 까지의 거리만 저장하면 최소 비용을 구할 수 있다.
  * [Minimum Path Cost in a Hidden Grid @ leetcode](https://leetcode.com/problems/minimum-path-cost-in-a-hidden-grid/)

# one src to all dst

* [bfs shortest path @ learntocode](/fundamentals/graph/bfsshortestpath/README.md) (unweighted graphs)
* [Dijkstra algorithm @ learntocode](/fundamentals/graph/dijkstra/README.md) (non-negative weighted graphs)
* [Bellman-Ford algorithm @ learntocode](/fundamentals/graph/bellmanford/README.md) (negative weighted graphs)

# all src to all dst

* [Floyd algorithm @ learntocode](/fundamentals/graph/floyd/README.md)
* Johnson’s algorithm
  