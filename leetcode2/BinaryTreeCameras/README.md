# Problem

[Binary Tree Cameras](https://leetcode.com/problems/binary-tree-cameras/)

Binary Tree 의 root node `u *TreeNode` 가 주어진다.  node 에 camera 를
설치하자. camera 가 설치된 noe 는 인접한 부모 혹은 자식을 감시할 수
있다.  최소 개수의 camera 를 구하라.

# Idea

DFS 로 탐색하고 leaf 부터 root 방향으로 camera 를 설치해보자.

다음과 같이 상태변수를 정의한다.

```
NO_NEED    : doesn't need a camera
HAS_CAMERA : has camera
NO_CAMERA  : There is no camera
```

NO_NEED 는 camera 를 설치할 필요가 없는 상태이다. 예를 들어 node u 에
대해 왼쪽 자식 혹은 오른쪽 자식에 camera 가 설치된 상태라면 node u 는
camera 를 설치할 필요가 없다.

NO_CAMERA 는 camera 를 설치하면 안되는 상태이다. 예를 들어 node u 에
대해 왼쪽 자식 혹은 오른쪽 자식이 없다면 camera 를 설치하지 말아야
최소 개수의 caemra 를 설치할 수 있다.

만약 tree 의 node 가 1 개 라면 root node 는 NO_CAMERA 상태일 것이다.
이때는 최소한 한대는 설치되어야 한다.

# Implementation

* [go](a.go)

# Complexity

```
O(N) O(lgN)
```
