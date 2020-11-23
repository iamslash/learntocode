# Problem

* [Count Univalue Subtrees](https://leetcode.com/problems/count-univalue-subtrees/)

# Idea

바이너리 트리의 루트노드 `u` 가 주어지면 univalue subtree 의 개수를 구하는
문제이다. univalue subtree 는 자신과 자식들 모두 같은 값을 가지고 있는
트리이다.

다음과 같은 부분문제를 정의한다.

```
bool isUni(TreeNode* u)

     u: visiting node
return: u is univalue subtree?
```

DFS 를 수행한다. 리프노드는 univalue subtree 에 해당한다.  바이너리
트리이기 때문에 첫번째 만나는 리프노드를 기준으로 univalue subtree
개수를 구해도 괜찮다.

다음과 같은 경우를 고려하여 `isUni` 를 구현한다.

```
   F        T     F     T     F     F     F     T
   
   NULL     5     5     5     5     5     5     5
                 /     /     / \   / \   / \   / \
                1     5     1   1 1   5 5   1 5   5
```


      5
     / \
    7   8

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
