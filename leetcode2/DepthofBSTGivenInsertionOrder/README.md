# Problem

[Depth of BST Given Insertion Order](https://leetcode.com/problems/depth-of-bst-given-insertion-order/)

수열 `order[]` 가 주어진다. `order[]` 는 `[1..n]` 의 permutation 으로 구성된다.
즉, 중복되는 숫자가 없다.

# Idea

예를 들어 `order = [2,1,4,3]` 의 경우를 살펴보자.

```

2      2        2          2
      /        / \        / \  
     1        1   4      1   4
                            /
                           3 
```

따라서 답은 3 이다.

부모 노드 `u` 가 있다고 해보자. `u` 의 왼쪽 자손들을 저장할 리스트를
`List<Integer> leftList` 라하고 오른쪽 자손들을 저장할 리스트를
`List<Integer> rightList` 라고 하자.

`order` 가 주어지면 `order[0]` 을 부모라 생각하고 나머지 자손들을
`leftList, rightList` 에 분배했다고 해보자. 그렇다면 최대 깊이는 `1 +
max(maxDepth of left List, maxDepth of right List)` 와 같다.

`maxDepth of` 를 다음과 같이 부분문제 `dfs` 로 정의한다.

```
int dfs(order) 

return: max depth of order
 order: given node numbers
```

`dfs` 를 다음과 같이 재귀적으로 구현한다.

* `order.size() <= 1` 이면 leaf node 이거나 null node 이다. 깊이는 1
  혹은 0 이다. `order.size()` 를 return 한다.
* `int n` 을 선언하여 `order` 의 길이를 저장한다.
* `int parentVal = order.get(0)` 를 선언하여 `order` 의 첫번째 원소를
  부모노드로 정한다.
* `List<Integer> leftList = new ArrayList<>()` 를 선언하여 부모 노드의
  왼쪽 자손들을 저장할 것이다.
* `List<Integer> rightList = new ArrayList<>()` 를 선언하여 부모
  노드의 오른쪽 자손들을 저장할 것이다.
* 인덱스 `i` 를 `[1..n)` 동안 순회하면서 `leftList, rightList` 에
  나누어 저장한다. 인덱스 `i` 는 곧 노드의 값과 같음을 주의하자.
* 이제 `parentVal` 을 값으로 하는 부모노드의 max depth 는 `1 +
  Math.max(dfs(leftList), dfs(rightList))` 와 같다.

# Implementation

* [java](MainApp.java)

# Complexity

```
O(N) O(N)
```
