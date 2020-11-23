# Problem

[Largest BST Subtree](https://leetcode.com/problems/largest-bst-subtree/)

# Idea

트리의 루트노드 `u` 가 주어지면 `BST` 를 구성하는 서브트리들 중
가장 큰 것의 크기를 구하는 문제이다.

다음과 같이 부분문제를 정의한다.

```
vector<int> dfs(TreeNode* u)

return: {min value in the subtree rooted with u,
         max value in the subtree rooted with u,
         max BST count in the subtree rooted with u}
```

예를 들어 트리가 다음과 같다고 해보자.

```
   10 
   / \ 
  5  15 
 / \   \ 
1   8   7
```

recursion tree 는 다음과 같다.

```
M: INT_MAX
m: INT_MIN
                               dfs(10):{m,M,3}
                     /                                  \
              dfs(5):{1,8,3}                      dfs(15):{m,M,1}
           /               \                    /            \
    dfs(1):{1,1,1}    dfs(8):{8,8,1}     dfs(N):{M,m,0} dfs(7):{7,7,1}
  /                 \
dfs(N):{M,m,0} dfs(N):{M,m,0}
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
