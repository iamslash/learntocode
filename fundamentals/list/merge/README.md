# Problem

singly linked list `a, b` 가 주어진다. `len(a) == len(b) or len(a) == len(b) + 1` 이다. `a, b` 를 merge 하자.

```
Input:
  a: 1 2 
  b: 4 5
Output: 
  1 4 2 5

Input:
  a: 1 2 3
  b: 4 5
Output:
  1 4 2 5 3
```

# Idea

다음과 같이 `p, q, r, s` 포인터를 이용하여 구현한다.

```
   p
     r
a: 1 2
b: 4 5
     s
   q

   p
     r
a: 1 2 3
b: 4 5
     s
   q
```

모든 반복을 마치면 `a` 가 곧 답이다.

# Implementation

* [java17](MainApp.java)
