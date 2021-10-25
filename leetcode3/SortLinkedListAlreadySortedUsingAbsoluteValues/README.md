# Problem

[Sort Linked List Already Sorted Using Absolute Values](https://leetcode.com/problems/sort-linked-list-already-sorted-using-absolute-values/)

Singly Linked List 의 head node 가 주어진다. 이 것을 non-decreasing
순서로 재배치하라.

# Idea

예를 들어 `head = [0,2,-5,5,10,-10]` 의 경우를 살펴보자.

```
h
0 -> 2 -> -5 -> 5 -> 10 -> -10
c
```

head node 를 h 라고 하고 current node 를 c 라고 하자.  h 부터 c 까지는
non-decreasing 이 되도록 유지하자. `c.next != null` 아닌 동안 c 를
전진한다.
 
```
h
0 -> 2 -> -5 -> 5 -> 10 -> -10
     c     t
```

이때 h 부터 c 까지 non-decreasing 이 되지 않는다.  non-decreasing 이
되기 위해 다음을 수행한다.

* `-5` 값을 갖는 node 를 t 라 하자.
* `c.next = t.next` 를 수행한다.
* `t.next = h` 를 수행한다.
* `h = t` 를 수행한다.

이제 h 부터 c 까지 non-decreasing 이 되었다.

```
 h
-5 -> 0 -> 2 -> -5 -> 5 -> 10 -> -10
 t         c
```

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(N) O(1)
```
