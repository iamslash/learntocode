# Materials

* [18.1 B-트리의 개념](https://www.youtube.com/watch?v=WBqKyrL6u-Q&list=PLl5LpJCoD2mCIRn0Fkt8z07EK320ZmHgY&index=139)
* [C++ Program to Implement B Tree](https://www.tutorialspoint.com/cplusplus-program-to-implement-b-tree)
  
# Abstract

B Tree 에 대해 정리한다.

# Datastructure BTree

B Tree 는 균형잡힌 트리이다. 균형잡힌 트리는 검색시간이 `O(lgN)` 이다. 하나의
노드가 최대 m 개의 자료가 배치될때 `m` 차 B Tree 라고 말한다. `m` 이 짝수 혹은 홀수
일 때 알고리즘이 다르다.

![](btree_order5.png)

다음은 B Tree 의 규칙이다.

* 노드의 자료수가 `n` 이면 자식의 수는 `n+1` 이어야 한다.
* 각 노드의 자료는 정렬된 상태여야 한다.
* 노드의 자료 Dk 의 왼쪽 서브트리는 Dk 보다 작은 값들이고 Dk 의 오른쪽 서브트리는 Dk 보다 큰 값들이어야 한다.
* root 노드는 적어도 2 개 이상의 자식을 가져야 한다.
* root 노드를 제외한 모든 노드는 적어도 m/2 개의 자료를 가지고 잇어야 한다.
* 외부노드로 가는 경로의 길이는 모두 같다.
* 입력자료는 중복될 수 없다.

# Algorithm Find

## Idea

## Complexity

# Algorithm Insert

## Idea

## Complexity

# Algorithm Delete

## Idea

## Complexity

# Implementation

* [c++11](a.cpp)
