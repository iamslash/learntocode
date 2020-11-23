# Problem

숫자 `N, K` 가 주어진다. `N` 에서 `K` 를 선택하는 모든 경우의
수열을 구하는 문제이다.

# Idea

`N` 에서 `K` 를 선택하는 조합과 같다. 

예를 들어 `N=3, K=2` 일때 backtracking 으로 다음과 같이 펼쳐볼 수 있다.

```
       0        1       
     /   \    /   
    1     2  2     
```

답은 `(0, 1), (0, 2), (1, 2)` 이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(nCk) O(n)
```