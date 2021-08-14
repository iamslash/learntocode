# Problem

[Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator/)

다음과 같은 member method 를 갖는 binary search tree iterator 를
구현한다.

* `public int next()`
* `public boolean hasNext()`

# Idea

stack 을 사용하여 구현해 본다. 

`stack` 에 저장된 `TreeNode` 는 그 값이 항상 내림차순으로 유지되야
한다. `next()` 가 호출되면 `stack` 에서 하나 꺼내어 그것을 `u` 라고
하자. `u.val` 을 리턴한다.  

이때 `u` 를 꺼낸 후 다음번 후보자들을 내림차순으로 저장해야 한다.
다음번 후보자들은 `u->right` 을 포함한 `u->right` 의 왼쪽 자손들이다.

`hasNext()` 의 경우 `stack` 이 비어 있는지 채워져 있는지 검사하여
구현한다.



# Implementation

* [c++11](a.cpp)
* [js](a.js)
* [java8](MainApp.java)

# Complexity

```
   next: O(N) O(N)
hasNext: O(1) O(N)
```
