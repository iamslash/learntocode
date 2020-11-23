# Problem

* [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)

# Abstract

``` 
            1
          /   \
        2       3
      /   \    /  \
     4     5  6    7      
```

위와 같은 트리가 있다고 해보자. 이것을 루트노드 부터 순회하는 방식은 다음과 같이 여러가지가 존재한다.

```
  in-order(left-root-right): 4 2 5 1 6 7 3
 pre-order(root-left-right): 1 2 4 5 3 6 7
post-order(left-right-root): 4 5 2 6 7 3 1
                        bfs: 1 2 3 4 5 6 7
                        dfs: 1 2 4 5 3 6 7
```

# recursion

## Idea

제일 쉽게 해결할 수 있는 방법이다. 다음과 같은
부분문제를 정의하고 재귀적으로 해결한다.

```
traverse(TreeNode* p) {
  traverse(p->left);
  print(p->val);
  traverse(p->right);
}
```

## Implementation

* [c++11](a.cpp)

## Complexity

```
O(N), O(N)
```

# stack

## Idea

`stack stck` 하나와 `TreeNode* p` 를 이용하여 다음과 같이 탐색한다.

```
while (p || stck.notempty()) {
  if (p) {
    stck.push(p)
    p = p->left
  } else {
    p = stck.pop()
    dosomething(p)
    p = p->right
  }
}
```

## Implementation

* [c++11](a.cpp)

## Complexity

```
O(N), O(N)
```

# morris traversal

## References

* [Threaded binary tree @ wikipedia](https://en.wikipedia.org/wiki/Threaded_binary_tree)
* [Morris traversal for Preorder @ geeksforgeeks](https://www.geeksforgeeks.org/morris-traversal-for-preorder/)

## Idea

![](https://upload.wikimedia.org/wikipedia/commons/7/7a/Threaded_tree.svg)

Threaded binary tree 오른쪽 널 포인터를 중위 후속자 노드로 연결하고, 왼쪽 널 포인터를 중위 선행자 노드로 연결한 것을 말한다. 이것은 `recursion, stack` 없이 in-order traversal 을 할 수 있는 방법으로 사용된다.

`stack, recursion` 없이 `TreeNode* cur, TreeNode* pre` 만을 이용하여 탐색하기 때문에 공간복잡도가 `O(1)` 이다. 

```
while (cur) {
  if (cur->left) {
    pre = cur->left
    while (pre->right && pre->right != cur)
      pre = pre->right
    if (pre->right == NULL) {
      pre->right = cur
      cur = cur->left
    } else {
      pre->right = NULL
      dosomething(cur)
      cur = cur->right
    }
  } else {
    dosomething(cur)
    cur = cur->right
  }
}
```

## Implementation

* [c++11](a.cpp)

## Complexity

```
O(N), O(1)
```
