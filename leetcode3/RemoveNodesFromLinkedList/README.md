# Problem

[Remove Nodes From Linked List](https://leetcode.com/problems/remove-nodes-from-linked-list/)

Linked List 의 head `head` 가 주어진다.  각 Node 마다 그 Node 의
값보다 큰 값을 갖는 Node 가 오른쪽에 있다면 그 Node 를 삭제하라. 
삭제된 Linked List 를 구하라.

# Idea

예를 들어 `head = [5,2,13,3,8]` 를 살펴보자.

```
head: 5 2 13 3 8
      x x  o x o      
```

따라서 답은 `[13,8]` 이다.

Linked List 의 head 부터 방문한다.  Node 를 방문할 때 마다 오른쪽으로
큰 값을 갖는 Node 가 있는지 검사해야 한다.

tail 부터 방문한다고 가정해보자. Node 를 방문할 때 마다 지금까지
출현했던 최대값보다 작은 값을 갖는 Node 라면 삭제한다. 훨씬 쉽다.

tail 부터 방문하는 것은 stack 을 이용해야 한다. call stack 을 stack
대신 이용해보자. recursion 으로 수월히 해결할 수 있다.

# Implementation

* [java11](MainApp.java)

# Complexity

```
O(N) O(N)
```
