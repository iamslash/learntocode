# Problem

singly linked list `head` 가 주어진다. `head` 를 뒤집어 보자.

# Idea

다음과 같이 `b, u, v` 포인터를 이용하여 구현한다.

```
ListNode b = null;
ListNode u = h;
while (u != null) {
    ListNode v = u.next;
    u.next = b;
    b = u;
    u = v;
}
return b;
```

예를 들어 `[0, 1, 2]` 를 살펴보자.

```
     b
head: 0 1 2
      u
      v
```

모든 반복을 마치면 `b` 가 곧 답이다.

# Implementation

* [java11](MainApp.java)
