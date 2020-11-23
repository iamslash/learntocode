# Problem

[Minimum Cost Tree From Leaf Values](https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/)

# Idea

수열 `A[]` 가 주어진다. `A[]` 를 이용하여 full binary tree 를 만들자.
즉, 모든 노드는 0 개 혹은 2 개의 자식들을 가지고 있다는 의미이다. leaf
node 가 아닌 node 들은 left subtree 의 최대 값과 right subtree 의 최대
값을 곱한 것을 값으로 갖는다. non-leaf node 들의 값의 합이 최소가
되도록 했을 때 그 합을 구하는 문제이다.

예를 들어 `A = [6, 2, 4]` 는 다음과 같이 full binary tree 를 만들 수
있다.

```
sum:  36           32

      24           24
     /  \         /  \
    12   4       6    8
   /  \              / \
  6    2            2   4
      
```

`A[]` 의 leaf node 두개를 짝지어야 한다. 짝지어진 두 node 의 값은
 `A[]` 에서 서로 인접한 수이어야 한다. 짝지어진 두 수를 곱한 다음 둘의
 최대 값을 어딘가에 보관한다. 나중에 다른 수와 곱해야 하기
 때문이다. 이때 non-leaf node 의 합이 최소가 되려면 짝지어진 leaf node
 는 각각 최대한 작아야 한다.
 
 `std::vector<int> stck = {INT_MAX}` 를 선언하여 `A[i]` 를 순회하면서
 내림차순으로 저장한다. stck 가 내림차순이면 `stck[1..]` 의 인접한
 두수를 짝지어 곱하고 더하여 `int ans` 에 저장한다. `ans` 는 left
 subtree 의 최대값과 right subtree 의 최대값을 곱하고 더하는 것과 같게
 된다.
 
 한편 `sum(non-leaf node)` 는 최소가 되어야 한다. 따라서 `stck` 가
 오름차순이 될 것 같으면 `stck` 에서 값을 하나 꺼내 `int mi` 에
 저장하고 인접한 두개의 수 중 작은 녀석을 선택하여 곱하고 답에 더한다.
 즉, `ans += mi * min(stck.back(), A[i])` 를 수행한다.
 
 다음은 `A = [6, 2, 4]` 의 풀이과정이다.
 
 ```
                i          i          i        
    A: 6 2 4    6 2 4    6 2 4    6 2 4    
 stck: M        M 6      M 6 2    M 6 4
  ans: 0                          8

                    i
 stck: M 6 4    M 6 4
  ans: 8        32                  
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
