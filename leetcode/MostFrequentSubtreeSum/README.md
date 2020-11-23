# Problem

* [Most Frequent Subtree Sum @ leetcode](https://leetcode.com/problems/most-frequent-subtree-sum/)

# Idea

서브트리가 리턴할 수 있는 숫자가 무엇들인지 이해해야 한다.
아래와 같이 몇가지 예를 정리해 본다.

```
  5
 /  \
2   -3

[2, -3, 4]
```

```
    1
   /  \ 
  5    3
 /  \
2   -3

[8, 3, 4, -2, 3]
```

`unordered_map<int, int> m_ump` 에 서브트리의 합과 발생횟수를 저장한다.
`m_max_cnt` 에 서브트리합의 발생횟수의 최대값을 저장한다.
DFS 를 수행하고 탐색의 종착지인 루트노드에 오게되면 지금까지 발생한 
최대의 서브트리합 발생횟수를 알수 있다. `m_ump` 를 순회하면서
`m_max_cnt` 와 같은 숫자들만 골라놓으면 답이된다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```