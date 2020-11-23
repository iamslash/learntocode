# Problem

[Move Sub-Tree of N-Ary Tree](https://leetcode.com/problems/move-sub-tree-of-n-ary-tree/)

p 를 q 의 자식으로 만드는 문제이다.

# Idea

다음과 같이 모든 경우의 수를 고려해야 한다.

* p 가 q 의 자식이다. 
  * 아무것도 할 필요가 없다.
* q 가 p 의 자손이다. 
  * q 를 부모에서 제거한다. p 의 자리에 q 를 저장한다. q 의 자식으로 p 를 부착한다.
* p 가 q 의 자손이다. 
  * p 를 부모에서 제거한다. q 의 자식으로 p 를 부착한다.
* p 가 q 의 자손이 아니고 q 가 p 의 자손이 아니다.
  * p 를 부모에서 제거한다. q 의 자식으로 p 를 부착한다.
  
`removeOrReplace(Node* u, Node* v, Node* r= NULL)` 를 선언하여 v 의
자리에 r 를 저장하거나 v 를 부모에서 제거한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
