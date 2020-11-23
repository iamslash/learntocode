# Problem

[Partition Array into Disjoint Intervals](https://leetcode.com/problems/partition-array-into-disjoint-intervals/)

# Idea

수열 `A` 가 주어진다. 두개의 그룹으로 분리해보자. 왼쪽 그룹의 모든 원소는
오른쪽 그룹의 원소들보다 작아야 한다. 그러한 조건을 만족하는 것들 중 
가장 작은 개수를 갖는 왼쪽 그룹의 크기를 구하는 문제이다.

왼쪽 그룹의 마지막 원소의 인덱스를 `int prtidx` 에 저장한다.  왼쪽
그룹의 원소들 중 가장 큰 값을 `int locmax = A[0]` 에 저장한다.  방문한
원소들 중 가장 큰 값을 `int glbmax` 에 저장한다. `locmax` 보다 작거나
같은 값들의 개수가 최소가 되게 `prtidx` 를 설정해야 한다. `A` 를
인덱스 `i` 를 이용하여 `[1..n)` 만큼 순회하면서 다음을 반복한다.

0. `locmax > A[i]` 이면 `A[i]` 는 왼쪽 그룹에 속해야 한다.
   `paridx = i` 를 수행한다. 그리고 지금껏 방문한 원소들 중 최대의 값
   `glbmax` 를 `locmax` 에 저장한다.
1. `locmax <= A[i]` 이면 `A[i]` 는 왼쪽 그룹에 속하지 않아도 된다.
   `glbmax = max(glbmax, A[i])` 를 수행한다.
   
모든 반복을 마치면 `prtidx + 1` 가 답이다.

다음은 `A = 5 0 3 8 6` 의 경우 풀이과정이다.

```
        i              i              i              i
     A: 5 0 3 8 6    5 0 3 8 6    5 0 3 8 6    5 0 3 8 6     
        p              p              p            p
locmax: 5            5            5            5
glbmax: 5            5            5            8

                i              i   
     A: 5 0 3 8 6    5 0 3 8 6     
            p            p             
locmax: 5            5            
glbmax: 8            8              
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
