# Problem

[Flip Columns For Maximum Number of Equal Rows](https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/)

# Idea

`0, 1` 로 구성된 행렬 `M[][]` 가 주어진다. 임의의 컬럼을 flipping 할
수 있다. 같은 숫자로 구성된 행의 최대 개수를 구하는 문제이다.

예를 들어 다음과 같은 경우를 살펴보자.

```
0 1
1 1 
```

```
0 1
1 0
```

```
0 0 0 
0 0 1
1 1 0
```

위의 예를 통해서 다음과 같은 규칙들을 발견할 수 있다.

* 특정 행과 같은 행이 있다면 두행은 임의의 컬럼을 flipping 하여 같은
  숫자로 구성할 수 있다.
* 특정 행의 반전된 것과 같은 행이 있다면 두행은 임의의 컬럼을 flipping 하여 같은
  숫자로 구성할 수 있다.

따라서 `M[][]` 의 행을 순회하면서 `M[i]` 와 같은 것 그리고 반전된 것의
개수의 합이 최대인 것이 답이다.

이것을 조금 더 최적화할 수 있다. 임의의 행 `M` 와 그것의 반전된 것 `I`
를 하나의 `K` 로 표현할 수 있다. 예를 들어 `M = 0 0 1, I = 1 1 0` 이라
하자. 가장 왼쪽의 숫자와 같은지 여부를 `K` 에 저장해 보자. `M = 0 0 1`
이면 `K = 1 1 0` 이고 `I = 1 1 0` 이면 `K = 1 1 0` 이다.  

따라서 `unordered_map<string, int> ump` 를 선언하여 `M[i]` 를
순회하면서 `K[i]` 를 저장한다. `ump[K[i]]` 중 가장 큰 값이 곧
답이된다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(RC) O(RC)

R : rows of M
C : cols of M
```
