# Problem

[Check Array Formation Through Concatenation](https://leetcode.com/problems/check-array-formation-through-concatenation/)

수열 `A[]` 와 수열의 모음 `P[][]` 가 주어진다. `P[i]` 를
연결하여 `A[]` 를 만들 수 있는지 검증하라. 단, `A[]` 의
숫자들은 모두 unique 하다. 역시, `P[][]` 의 숫자들도
unique 하다.

# Idea

`A[]` 의 숫자들이 distinct 하고 `P[][]` 의 숫자들이 distinct 하므로
hash map 을 이용한다.

`pieceMap` 을 선언하여 `P[i][0] : P[i]` 를 저장한다.

`flatten` 을 선언한다. 인덱스 `i` 
를 이용하여 `A[]` 를 처음부터 끝까지 순회하며 다음을 반복한다.

* `pieceMap[A[i]]` 를 `flatten` 의 뒤에 삽입한다.

모든 반복을 마치고 `flatten` 과 `A[]` 를 비교하여 리턴한다.

# Implementation

* [c++11](a.cpp)
* [py3](a.py)

# Complexity

```
O(N) O(N)
```
