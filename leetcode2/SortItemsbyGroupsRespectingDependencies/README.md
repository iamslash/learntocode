# Problem

[Sort Items by Groups Respecting Dependencies](https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/)

# Idea

`vector<int> groupOrder` 를 선언하여 group 의 순서를
저장한다. `vector<vector<int>> groupItemOrder` 를 선언하여 group 별
item 의 순서를 저장한다. 만약 i-item 이 속한 group 이 없다면 별도의
group 을 생성한다. 순서를 저장하기 위해서는 [toplogical
sort](/fundamentals/graph/topologicalsort/README.md) 를 이용한다.

두 번의 [toplogical
sort](/fundamentals/graph/topologicalsort/README.md) 를 해야 하기
때문에 [toplogical
sort](/fundamentals/graph/topologicalsort/README.md) 를 수행할 수 있는
`class Graph` 를 제작한다.

`Graph groupGrah`, `vector<Graph> groupItemGraph` 를 선언하여 각각
group 의 graph, 특정 group 에 속한 item 들의 graph 를 저장한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2) O(N^2)
```
