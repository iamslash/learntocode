# Problem

[Diameter of N-Ary Tree](https://leetcode.com/problems/diameter-of-n-ary-tree/)

n-ary tree 의 root node `Node* u` 가 주어진다. 가장 긴 트리의 지름을
구하라. 트리의 지름은 임의의 노드로 부터 두개의 leaf node 까지의
거리의 합이 가장 긴 것이다.

# Idea

다음과 같은 부분문제 `dfs` 를 선언하여 재귀적으로 해결한다.

```cpp
int dfs(Node* u)

return: maximum distance to leaf node
     u: this node
```

`int ans` 를 선언하여 답을 저장한다.  임의 노드 `u` 를 방문했다고
하자. `int cost_1st, cost_2nd` 를 선언하고 leaf node 까지의 최대
길이와 그 다음 최대 길이를 저장한다.

이제 `ans = max(ans, cost_1st, cost_2nd)` 이다. 

`dfs` 는 `u` 까지의 거리 ` 을 포함하여 `cost_1st + 1` 을 리턴한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
