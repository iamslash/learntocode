# Problem

[Unique Binary Search Trees II](https://leetcode.com/problems/unique-binary-search-trees-ii/)

숫자 `n` 이 주어진다. `[1..n]` 의 숫자들을 이용해서
만들 수 있는 BST 를 구하라.

# Idea

예를 들어 `n = 3` 인 경우 다음과 같은 BST 를 만들 수 있다.

```
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
```

부분문제 `dfs` 를 다음과 같이 정의하고 구현한다.

```c
vector<TreeNode*> dfs(int from, int to)

return: possible BST with [fr..to]
    fr: from number
    to: to number
```
* `vector<TreeNode*> ans` 를 선언하여 `fr, to` 를 이용하여 만들 수
  있는 `BST` 의 root node 를 저장한다.
* `fr == to` 이면 `ans` 에 `new TreeNode(fr)` 를 삽입한다.
* `fr > to` 이면 만들 수 있는 BST 가 없다. `ans` 에 `NULL` 를 삽입한다.
* `fr < to` 이면 `[fr..to]` 의 각 숫자들을 root node 로 하는 BST 를
  만들 수 있다. 그 root node 들을 `ans` 에 삽입한다. 인덱스 `i` 를
  `[fr..to]` 동안 순회하면서 다음을 반복한다.
  * `vector<TreeNode*> l` 를 선언하여 `dfs(fr, i-1)` 를 저장한다.
  * `vector<TreeNode*> r` 를 선언하여 `dfs(i+1, to)` 를 저장한다.
  * 이제 인덱스 `j, k` 를 각각 `[0..l.size()), [0..r.size())` 동안
    순회하면서 다음을 반복한다.
    * `TreeNode* t = new TreeNode(1)` 를 선언한다.
    * `t` 의 왼쪽 자식으로 `l[j]` 를 저장한다.
    * `t` 의 오른쪽 자식으로 `r[j]` 를 저장한다.
    * `ans` 에 `t` 를 추가한다.

# Implementation

* [c++11](a.cpp)
* [java8](Solution.java)

# Complexity

```
O(N) O(lgN)
```
