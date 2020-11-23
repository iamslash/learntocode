# Problem

[Construct Binary Tree from Preorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/)

# Idea

트리의 프리오더 수열 `pre[]` 과 포스트오더 수열 `pst[]` 가 주어진다.
트리를 구하는 문제이다.

recursive way 를 사용할 수 있지만 iterative way 를 사용하면
공간복잡도를 더욱 낮출 수 있다.

`stack<int> stck` 를 선언하고 `stck.push(new TreeNode(pre[0]))` 를
수행한다. 트리의 루트를 리턴해야 하므로 `TreeNode* h = stck.top()` 를
수행한다.  `stck.top()` 은 이번에 생성한 노드를 삽입할 부모가 저장되어
있어야 한다.  두개의 인덱스 `i, j` 를 사용하여 각각 `pre[]` 와 `pst[]`
를 순회한다.

먼저 인덱스 `i` 를 이용하여 `[1..n-1]` 를 순회하면서 다음을 반복한다.

* `TreeNode* u = new TreeNode(pre[i])` 를 수행한다. 
* `stck.top()` 이 `pst[j]` 와 같다면 그렇지 않을 때까지 `stck.pop(),
  ++j` 를 수행하여 `stck.top()` 이 `u` 를 삽입할 부모가 되도록 하자.
* `stck.top()->left == NULL` 이면 `stck.top()->left = u` 를,
  `stck.top()->right == NULL` 이면 `stck.top()->right = u` 를
  수행하자.
* `stck.push(u)` 를 수행한다. 다음번 방문할 노드가 `u` 의 자식일 수
  있다.

모든 반복이 완료되면 `h` 를 리턴한다.

다음은 `pre[] = 1 2 4 5 3 6 7, pst[] = 4 5 2 6 7 3 1` 의 풀이
과정이다.

```
     i
pre: 1 2 4 5 3 6 7                   1
pst: 4 5 2 6 7 3 1
     j
stk: 1

       i
pre: 1 2 4 5 3 6 7                   1
pst: 4 5 2 6 7 3 1                  /
     j                             2
stk: 1 2

         i
pre: 1 2 4 5 3 6 7                   1
pst: 4 5 2 6 7 3 1                  /
     j                             2
stk: 1 2 4                        /
                                 4
                                 
           i
pre: 1 2 4 5 3 6 7                   1
pst: 4 5 2 6 7 3 1                 /
       j                          2
stk: 1 2 5                       / \
                                4   5

             i
pre: 1 2 4 5 3 6 7                   1
pst: 4 5 2 6 7 3 1                 /   \
           j                     2       3
stk: 1 3                        / \
                               4   5

               i
pre: 1 2 4 5 3 6 7                   1
pst: 4 5 2 6 7 3 1                 /   \
           j                     2       3
stk: 1 3 6                      / \     / 
                               4   5   6 

                 i
pre: 1 2 4 5 3 6 7                   1
pst: 4 5 2 6 7 3 1                 /   \
             j                   2       3
stk: 1 3                        / \     / \ 
                               4   5   6   7
```
  
# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
