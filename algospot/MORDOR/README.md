# Problem

[MORDOR](https://algospot.com/judge/problem/read/MORDOR)

# Idea

일정한 구간에서 최소값과 최대값을 발견해서 차이값을 구하면 답이 된다.
하나의 입력데이터에 대해 다양한 질의가 있기 때문에 segment tree를
제작해서 해결한다.  [RMQ](/doc/tree_rmq.md)를 참고해서 segment tree를
제작하면 일정한 범위의 최소값을 쉽게 구할 수 있다.  만약
입력데이터들에 `-1`을 곱하여 동일한 RMQ logic을 이용하여 segment
tree를 제작하면 최대값을 얻어낼 수 있다. segment tree를 두번 제작해도
시간복잡도는 `O(N)`이다.

# Implementation

[c++11](a.cpp)

# Time Complexity

```
O(N)  : build segment tree
O(lgN): query
```

# Space Complexity

```
O(N) : segment tree
```
