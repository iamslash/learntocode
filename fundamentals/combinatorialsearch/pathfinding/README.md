- [Abstract](#abstract)
- [one src to one dst](#one-src-to-one-dst)
- [one src to all dst](#one-src-to-all-dst)
- [all src to all dst](#all-src-to-all-dst)
- [Shortest Path Cost](#shortest-path-cost)

----

# Abstract

* 길 찾기 문제를 해결할 수 있는 전략들에 대해 적는다.

# one src to one dst

* [Dijkstra algorithm @ learntocode](/fundamentals/graph/dijkstra/README.md) (non-negative weighted graphs)
  * `dist[]` 를 보관할 필요는 없다. `src` 에서 `dst` 까지의 거리만 필요하다.
  * [Minimum Path Cost in a Hidden Grid](/leetcode2/MinimumPathCostinaHiddenGrid/README.md)
* [A* @ learntocode](/fundamentals/combinatorialsearch/astar/README.md)
  
# one src to all dst

* [bfs shortest path @ learntocode](/fundamentals/graph/bfsshortestpath/README.md) (unweighted graphs)
* [Dijkstra algorithm @ learntocode](/fundamentals/graph/dijkstra/README.md) (non-negative weighted graphs)
* [Bellman-Ford algorithm @ learntocode](/fundamentals/graph/bellmanford/README.md) (negative weighted graphs)

# all src to all dst

* [Floyd algorithm @ learntocode](/fundamentals/graph/floyd/README.md)
* Johnson’s algorithm

# Shortest Path Cost

모든 거리의 비용이 1 이다. [bfs](/fundamentals/graph/bfs/README.md) 를 이용하여 최단 거리 경로의 비용을 구할 수 있다.

* [L](/leetcode3/MinimumOperationstoConvertNumber/README.md) | [Minimum Operations to Convert Number](https://leetcode.com/problems/minimum-operations-to-convert-number/)
  * cost of edge is 1 and finding shortest path cost 
  