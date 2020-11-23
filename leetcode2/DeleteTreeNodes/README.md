# Problem

[Delete Tree Nodes](https://leetcode.com/problems/delete-tree-nodes/)

# Idea

노드의 개수 `n`, 부모노드 번호의 모임 `P[]`, 노드별 값의 모임 `V[]` 가
주어진다.  특정 노드를 포함한 서브트리의 값의 합이 0 이 되면
서브트리를 제거한다. 제거하고 남은 노드의 개수를 구하는 문제이다.

![](https://assets.leetcode.com/uploads/2019/07/02/1421_sample_1.PNG)

`int[] ans = new[n]` 를 선언하여 `i` 노드를 중심으로 남은 노드의
개수를 저장한다. `V[i]` 는 i node 를 포함한 서브트리의 합을 저장한다.

잎 노드부터 루트 노드까지 거슬러 올라가면서 다음을 반복한다.

* `V[P[i]] += V[i]` 를 수행한다. 
* `V[i]` 가 0 이 아닐 때 마다 `ans[P[i]]` 를 하나 늘린다.

모든 반복을 마치고 `ans[0]` 이 0 이 아니면 `ans[0]+1` 이 답이다. 

# Implementation

* [java8](a.java)

# Complexity

```
O(N) O(N)
```
