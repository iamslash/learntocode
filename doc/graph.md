# Abstract

- 그래프에 대해 적어보자.

# 유용한 용어들

- vertex, edge
  - 그래프의 최소 구성 요소이며 정점과 간선이라고 한다.

- directed graph
  - 간선의 방향이 존재하는 그래프

- undirected graph
  - 간선의 방향이 존재하는 그래프

- weighted graph
  - 간선에 가중치가 존재하는 그래프

- multi graph
  - 두 vertex 사이에 두개 이상의 edge 가 존재하는 graph

- simple graph
  - 두 vertex 사이에 한개의 edge 만 존재하는 graph

- unrooted tree

  ![](https://www.ncbi.nlm.nih.gov/Class/NAWBIS/Modules/Phylogenetics/images/phylo1002.gif)

- bipartite graph

  - 그래프의 정점들을 겹치지 않는 두개의 그룹으로 나눠서 서로 다른
    그룹에 속한 정점들 간에만 간선이 존재하도록 만들 수 있는 그래프

  - ![](https://upload.wikimedia.org/wikipedia/commons/thumb/e/e8/Simple-bipartite-graph.svg/220px-Simple-bipartite-graph.svg.png)

- DAG (directed asyclick graph)
  - 방향그래프 이면서 사이클이 없는 그래프
  
  - ![](https://upload.wikimedia.org/wikipedia/commons/thumb/c/c6/Topological_Ordering.svg/220px-Topological_Ordering.svg.png) 

- simple path
  - 한 정점을 최대 한번만 지나는 경로

- cycle, circuit
  - 시작한 점에서 끝나는 경로

- adjacency list 
  - `vector<list<bool>> adj`;
  - `O(|V| + |E|)` 크기의 공간을 갖는다.

- adjacency matrix 
  - `vector<vector<bool> > adj`;
  - `O(|V|^2)` 크기의 공간을 갖는다.

- sparse graph
  - edge 의 수가 `|V|^2` 에 비해 훨씬 적은 그래프

- dense graph
  - edge 의 수가 `|V|^2` 에 비례 하는 그래프

- implicit graph
  - 어떠한 문제가 명시적으로 그래프 처럼 보이지 않을때 암시적으로
    정점과 간선으로 표현 가능한 그래프

- spanning tree
  - 그래프에서 일부 간선을 제거하고(= 일부 간선만 선택하여) 모든 정점이 연결되도록 만든 트리

# 유용한 문제의 유형들

- 그래프를 저장하는 방법 세가지는 인접행렬, 인접리스트, 간선리스트이다.
- DFS
- BFS
- connected component
- bipartite graph
- implicit graph
- cycle
- flood fill algorithm
- topological sort
- prim algorithm
- kruskal algorithm
- shortest path algorithm
- bellman ford algorithm
- djikstra algorithm
- floyd algorithm
- eulerian circuit
- SCC(strongly connected components)
- Kosaju's algorithm
- Tarjan's algorithm
- DFS tree
- cut vertex
- bridge
- 2-SAT