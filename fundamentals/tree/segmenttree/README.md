- [Abstract](#abstract)
- [Data Structure Segment Tree](#data-structure-segment-tree)
- [Algorithm Init](#algorithm-init)
  - [Idea](#idea)
  - [Complexity](#complexity)
- [Algorithm Query](#algorithm-query)
  - [Idea](#idea-1)
  - [Complexity](#complexity-1)
- [Algorithm Update](#algorithm-update)
  - [Idea](#idea-2)
  - [Complexity](#complexity-2)
- [Implementation](#implementation)

-----

# Abstract

`segment tree` 는 일정한 범위에 대한 연산을 빠르게 하기 위한 자료구조이다.
예를 들어서 일정한 범위에 대한 최소값 혹은 최대값을 구하거나 일정한
범위에 대한 최빈값을 구하는 경우에 사용한다.

# Data Structure Segment Tree

`N` 개의 입력 데이터 `V[]` 가 있다고 하자. 이것을 구간트리로 만들어 두면
일정한 범위에 대한 연산을 `O(lgN)` 의 시간으로 수행할 수 있다.
구간트리는 complete binary tree 이다. 

complete binary tree 는 마지막 level 를 제외한 모든 level 이
채워져 있고 마지막 level 의 모든 노드들은 왼쪽으로 채워져 있다.

![](/_img/BinaryTree.png)

complete binary tree 는 포인터를 이용하는 것보다 일차원 배열로 표현하는
것이 메모리를 더욱 절약 할 수 있다. [heap](/fundamentals/tree/heap/README.md) 의 구현과 비슷하다.

![](/_img/segmenttree.png)

위 그림은 입력데이터가 `V[] = 1, 3, 7, 9, 2, 4, 3, 2` 일때
생성한 구간트리이다. 파란색 숫자는 구간트리 배열 `m_arr[]` 의 인덱스이고
빨간색 숫자는 입력데이터 배열 `V[]` 의 인덱스이다. leaf node 를 제외한
노드는 특정 구간의 최소 값이 저장되어 있음을 주목하자.

입력 데이터의 개수가 `N` 이라면 구간트리 배열 `m_arr[]` 의 크기는 얼마로 해야할까?
입력 데이터는 구간 트리의 leaf node 에 해당한다. leaf node 를 제외한
node 들은 구간에 대한 정보를 담고 있다. 구간 트리가 complete binary
tree 이기 때문에 leaf node 들의 개수는 N 보다 크거나 같은 2 의 승수이어야
한다. 이것을 `T` 라 하면 구간트리 배열의 크기는 다음과 같다.

```
length of m_arr = T + T - 1
                = 2T - 1
```

complete binary tree 에서 leaf node 의 개수가 `T` 라면 leaf node 보다
레벨이 작은 녀석들의 개수는 `T-1` 이다. N 보다 크거나 같은 2 의 승수 `T` 를
찾는 것이 번거롭다면 구간트리 배열의 개수를 `4N` 으로 해도 좋다.

구간트리는 제작할때 `O(N)` 만큼 걸리고 질의할때 `O(lgN)` 만큼 걸린다.
하나의 입력 데이터에 대해 여러개의 질의가 있을때 유용하다.

루트 노드의 값을 `m_arr[1]` 에 저장했다면 임의의 노드 `m_arr[i]` 의 왼쪽
자손과 오른쪽 자손의 값을 각각 `m_arr[2*i]`, `m_arr[2*i+1]` 이라고 할 수 있다.
언급한 계산식을 이용하여 재귀적으로 자손을 접근하면 구간트리를
수월하게 구현할 수 있다.

구간 트리의 주요 함수들은 다음과 같다.

```cpp
int init(const std::vector<int>& V, int vleft, int vright, int rmidx);
int query(int vleft, int vright);
int query(int qvleft, int qvright, int rmidx, int vleft, int vright);
int update(int vidx, int value, int rmidx, int vleft, int vright);
```

# Algorithm Init

## Idea

![](/_img/segmenttree.png)

`init` 은 입력데이터를 이용하여 구간트리 배열을 재귀적으로
채운다. 채워지는 순서를 위그림의 파란색 숫자로 나타내면 
`8, 9, 4, 10, 11, 5, 2, 12, 13, 6, 14, 15, 7, 3, 1` 과 같다. 

`rmidx` 는 `m_arr[]` 의 인덱스이고 `vleft, vright` 는 rmidx 의 값에
대응하는 `V[]` 의 구간을 의미한다.  구간트리의 모든 노드의 개수는
`4N` 이기 때문에 `init` 의 시간복잡도는 `O(N)` 이다.

## Complexity

```
O(N) O(N)
```

# Algorithm Query

## Idea

`query` 는 입력데이터의 특정한 구간의 최소 값을 재귀적으로 얻어온다.
`qvleft, qvright` 는 입력데이터의 특정한 구간이고 `rmidx` 는 `m_arr[]` 의 인덱스이다. `vleft, vright` 는 rmidx 의 값에 대응하는 `V[]` 의 구간을 의미한다.

`[qvleft, qvright]` 를 질의 구간이라고 하고 `[vleft, vright]` 담당
구간이라고 하자.  질의 구간과 담당 구간의 관계는 총 3 가지 경우가
가능하다.  첫번째는 질의 구간과 담당 구간이 전혀 겹치지 않는 경우이고
두번째는 질의 구간이 담당 구간을 포함하는 경우이고 세번째는 질의
구간이 담당 구간과 일부 겹치는 경우이다.

첫번째의 경우는 질의 구간과 담당 구간이 전혀 상관없기 때문에 상위
함수의 `min` 에서 걸러지기 위해 아주 큰값을 리턴한다.  두번째의 경우는
담당 구간의 최소값만 리턴해도 상위 함수의 `min` 에서 처리 가능하다.
세번째의 경우는 다시 재귀적으로 해결한다.

## Complexity

```
O(lgN) O(1)
```

# Algorithm Update

## Idea

`update` 는 입력데이터의 특정한 값을 재귀적으로 변경한다. 이때 구간트리
배열의 관련된 값들도 같이 변경되어야 한다.

## Complexity

```
O(lgN) O(1)
```

# Implementation

* [c++11](a.cpp)
