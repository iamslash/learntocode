# Abstract

한 점이 다각형의 내부에 있는지 외부에 있는지 확인해 보자.

# References

* [How to check if a given point lies inside or outside a polygon? @ geeksforgeeks](http://www.geeksforgeeks.org/how-to-check-if-a-given-point-lies-inside-a-polygon/)

# Idea

특정 점에서 우측으로 무한의 반직선을 긋는다. 다각형과
교점이 홀수이면 다각형의 안쪽에 있고 짝수이면 바깥쪽에 있다.
다각형의 선분과 반직선이 겹치는 경우는 어떻게 하지???

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```