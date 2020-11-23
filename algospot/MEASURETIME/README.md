<!-- markdown-toc start - Don't edit this section. Run M-x markdown-toc-refresh-toc -->
**Table of Contents**

- [Problem](#problem)
- [Strategy Fenwick Tree](#strategy-fenwick-tree)
    - [Idea](#idea)
    - [Implementation](#implementation)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)
- [Strategy Segment Tree](#strategy-segment-tree)
    - [Idea](#idea-1)
    - [Implementation](#implementation-1)
    - [Time Complexity](#time-complexity-1)
    - [Space Complexity](#space-complexity-1)
- [Strategy BST](#strategy-bst)
    - [Idea](#idea-2)
    - [Implementation](#implementation-2)
    - [Time Complexity](#time-complexity-2)
    - [Space Complexity](#space-complexity-2)
- [Strategy Merge Sort](#strategy-merge-sort)
    - [Idea](#idea-3)
    - [Implementation](#implementation-3)
    - [Time Complexity](#time-complexity-3)
    - [Space Complexity](#space-complexity-3)

<!-- markdown-toc end -->


-------------------------------------------------------------------------------

# Problem

[삽입 정렬 시간 재기 @ algospot](https://algospot.com/judge/problem/read/MEASURETIME)

# Strategy Fenwick Tree

## Idea

삽입정렬 할 때 `A[i]` 가 왼쪽으로 몇번 움직이는지를 알려면
`A[0...i-1]` 에 `A[i]` 보다 큰 수가 몇개 있는지를 알아야 한다.  `i` 를
`0` 부터 `N-1` 까지 순회하면서 `A[i]` 가 출현 할 때 마다 그동안 출현한
`A[0...i-1]` 들을 기반으로 큰수가 얼마나 있는지를 빠르게 확인 할 수
있는 무언가가 필요하다.

`A[i]` 의 출현 여부를 이용하여 펜윅 트리를 만들자.
`tree[i]` 는 `A[i]` 가 몇번 출현 했는지를 저장한다.
입력데이터 `A` 는 중복 되지 않은 숫자들의 모임이기 때문에
`tree[i]` 는 `0` 아니면 `1` 이다. 

이때 `i` 를 `0` 부터 `N-1` 까지 순회하면서 다음과 같이 수행하자.
`A[i]` 보다 큰 수를 `tree[N-1] - tree[A[i]]` 를 이용하여 구하고
`r` 에 저장하자.
`FenwickTree::Add(A[i], 1)` 를 이용하여 `A[i]` 가 하나 출현 되었다고
표시하자. `r` 의 합이 답이다.


## Implementation

* [c++11](a.cpp)

## Time Complexity

```
O(NlgN)
```

## Space Complexity

```
O(N)  : build fenwick tree
O(lgN): call stack for fenwick tree add 
O(lgN): call stack for fenwick tree sum
```

# Strategy Segment Tree

## Idea

펜윅 트리와 비슷하게 구현한다. 그러나 펜윅 트리가 구현이 더욱 간단하다.

# Strategy Treap

## Idea

[Treap::count_less_than](/doc/tree_treap.md)를 이용하여 `A[i]` 보다 큰
수를 구할 수 있다. 그러나 펜윅 트리가 시간 복잡도는 같지만 구현이 더욱
간단하다.

## Implementation

* [c++11](b.cpp)

## Time Complexity

```
O(NlgN)
```

## Space Complexity

```
O(N)  : build Treap
O(lgN): call stack for Treap CountLessThan
O(lgN): call stack for Treap Insert
```

# Strategy Merge Sort

## Idea


## Implementation

[c++11](c.cpp)

## Time Complexity

```
O(NlgN)
```

## Space Complexity

```
```
