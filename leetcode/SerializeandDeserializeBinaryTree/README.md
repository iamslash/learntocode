# Problem

[Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)

# Idea

예를 들어 다음과 같은 binary tree 를 살펴보자.

```
     1
   /   \
  2     3
      /   \
     4     5
```

이것을 다음과 같은 규칙을 이용하여 serialize 해보자. 

* pre-order 탐색을 한다.
* 원소를 구분하기 위해 문자열 `","` 를 사용하자.
* 자식이 없다는 것을 위해 문자열 `"N"` 를 사용하자.

```
1,2,N,N,3,4,N,N,5,N,N,
```

이번에는 다음과 같은 규칙을 이용하여 string 을 deserialize 해보자.

* pre-order 탐색을 한다.
* 문자열을 `","` 으로 split 하면 원소들의 리스트를 얻어올 수 있다.
  이것을 `nodes` 라고 하자.
* `nodes` 의 처음 원소는 지금 만들어야할 `node` 를 의미한다.

# Implementation

* [c++11](a.cpp)
* [java17](MainApp.java)

# Complexity

```
O(N) O(lgN)
```
