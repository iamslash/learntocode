# Problem

```
     1
    / \
   2   3
  / \
 4   5
```

Binary Tree Traversals

* Inorder (Left, Root, Right) : 4 2 5 1 3
* Preorder (Root, Left, Right) : 1 2 4 5 3
* Postorder (Left, Right, Root) : 4 5 2 3 1

```
     4
    / \
   2   5
  / \
 1   3
```

Binary Search Tree Traversals

* Inorder (Left, Root, Right) : 1 2 3 4 5
* Preorder (Root, Left, Right) : 4 2 1 3 5
* Postorder (Left, Right, Root) : 1 3 2 5 4

Inorder traversal of BST (Binary Search Tree) means sorted numbers

# Implementation

If you use stack, you can traverse inorder by iterative way.

* [inorder recursively](recursiveinorder.cpp)
* [inorder iteratively](iterativeinorder.cpp)
* [inorder recursively with prev node](recursiveinorderprev.cpp)
* [preorder recursively](recursivepreorder.cpp)
* [preorder iteratively](iterativepreorder.cpp)
* [postorder recursively](recursivepostorder.cpp)
* [postorder iteratively](iterativepostorder.cpp)

# References

* [Tree Traversals (Inorder, Preorder and Postorder)](https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/)
