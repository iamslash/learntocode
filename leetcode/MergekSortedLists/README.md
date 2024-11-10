# Problem

[Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/)

리스트들의 리스트 `lists[][]` 가 주어진다. 모든 리스트들을 merge 한
리스트를 구하라.

# Heap

## Idea

이 방법은 최소 힙을 사용하여 각 리스트의 첫 번째 원소들을 우선순위 큐에 넣는 방식입니다. 힙은 항상 가장 작은 원소를 맨 위에 두므로, 힙에서 꺼낸 원소를 결과 리스트에 추가하고, 그 원소의 다음 노드가 있다면 다시 힙에 넣어 계속 반복합니다. 이렇게 하면 모든 원소를 오름차순으로 정렬된 상태로 결과 리스트에 추가할 수 있습니다.

## Implementation

* [java17](MainApp.java)

## Complexity

```
O(NlgK) O(K)
N: num of items
K: num of lists
```

# Recursive Divide Conquer

## Idea

리스트들을 쪼개고 병합하는 과정을 재귀적으로 수행합니다. 예를 들어, 주어진 리스트가 4개일 경우, 왼쪽 2개와 오른쪽 2개로 나눈 후 각 부분 리스트들을 정렬하여 병합합니다. 이 과정을 계속해서 더 작은 단위로 쪼개면서 진행하고, 마지막에는 병합된 하나의 리스트가 남습니다.

분할 정복 방법은 각 병합 단계에서 모든 노드를 다루며, 단계가 `logK` 단계로 나뉘기 때문에 전체 시간 복잡도는 `𝑂(𝑁lg𝐾)` 입니다.

```
lists: 1 2 3 
       2 3 4
       3 4 5
       4 5 6 

dfs(0, 3): 
  dfs(0,1) 
     dfs(0,0)
     dfs(1,1)
  dfs(2,3) 
     dfs(2,2)
     dfs(3,3)
```

아래와 같이 `lists[][]` 의 모든 node 를 방문하는 것을 `lgK` 번만큼 수행한다. 따라서 시간복잡도는 `O(NlgK)` 이다.

```

1. dfs(0, 3)

2.  dfs(0,1) 
    dfs(2,3) 

3.     dfs(0,0)
       dfs(1,1)
       dfs(2,2)
       dfs(3,3)
```

## Implementation

* [java17](MainApp.java)

## Complexity

```
O(NlgK) O(lgK)
N: num of items
K: num of lists
```

# Iterative Divide Conquer

## Idea

재귀 대신 반복 구조를 사용하여 리스트를 두 개씩 병합합니다. 처음에는 인접한 리스트들끼리 병합하고, 다시 병합된 리스트들끼리 병합하는 식으로 반복합니다. 단계가 진행될수록 리스트의 개수가 절반으로 줄어들며 병합되므로 최종적으로 하나의 리스트가 남게 됩니다.

이 방법 또한 전체 노드 수 N을 다루면서 병합 단계가 `logK`만큼 반복되므로 `O(NlogK)`입니다. 추가 메모리 사용이 적어 공간 복잡도는 O(1)입니다.

## Implementation

* [java17](MainApp.java)

## Complexity

```
O(NlgK) O(1)
N: num of items
K: num of lists
```
