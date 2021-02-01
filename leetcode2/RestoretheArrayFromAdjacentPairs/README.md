# Problem

[Restore the Array From Adjacent Pairs](https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/)

간선의 모음 `E[][]` 가 주어진다. 수열 `orgNums[]` 은 unique 한 `n` 개
숫자들의 모음이다. `E[][]` 는 `n-1` 개이다. `E[i][0]` 은 `E[i][1]` 과
`orgNums[]` 에서 서로 인접해 있다. `orgNums` 를 구하라.

# Idea

예를 들어 `E = [[2,1],[3,4],[3,2]]` 의 경우를 살펴보자.

`unordered_map<int, vector<int>> adjMap` 을 선언하여 `{num : [adjacent num,...]}` 을 저장한다. `vector<int> ans` 를 선언하여 답을 저장한다. `orgNums` 는 distinct 하기 때문에 `adjacent num` 의 길이는 항상 2 보다 작거나 같다.

```
       E: [2,1],[3,4],[3,2]]
  adjMap: 1 2 3 4 
          2 1 2 3
            3 4
     ans: 1 2 3 4
              p t
```


`orgNums` 는 `n` 개 이고 `E[][]` 의 개수는 `n-1` 개 이다. 또한 `orgNums[]`
의 숫자들은 unique 하다. `orgNums` 의 첫번째 숫자를 찾고 그것을 이어 붙이기만 하면
답을 구할 수 있다. [greedy algorithm](/doc/greedy_proof.md) 으로 해결할 만 하다.

`auto& e` 로 `E` 를 순회하며 다음을 반복한다.
* `adjMap` 에 `{e[0] : e[1]}`, `{e[1] : e[0]}` 을 삽입한다.

`auto& u` 로 `adjMap` 를 순회하며 다음을 반복한다.
* `u.second.size() == 1` 이면 `orgNums` 의 시작 혹은 끝 숫자가 포함된 연결을 찾은 것이다. 둘 중 처음 만나는 것을 `ans` 에 저장한다. 즉, `ans.push_back(u.first), ans.push_back(u.second[0])` 를 수행하고 반복을 마친다. 

`orgNums` 를 거꾸로 뒤집으면 다른 숫자를 만들 수 있기 때문에 첫번째 만나는 숫자를 구하고 반복을 마쳐도 된다.

이제 `ans[]` 에는 `orgNums` 의 시작 혹은 끝 숫자를 포함한 두개의 숫자가 저장되어 있다. 

`ans.size() <= E.size()` 동안 다음을 반복한다.

* `int tail = ans.back()` 를 선언한다.
* `int prev = ans[ans.size()-2]` 를 선언한다.
* `auto& next = adjMap[tail];` 를 선언한다.
* `next[0] != prev` 이면 `ans` 에 `next[0]` 를 저장한다.
* `next[0] == prev` 이면 `ans` 에 `next[1]` 를 저장한다.

모든 반복을 마치면 `ans` 가 곧 답이다.

# Implementation

* [c++11](a.cpp)
* [java8](Solution.java)

# Complexity

```
O(E) O(E)
```
