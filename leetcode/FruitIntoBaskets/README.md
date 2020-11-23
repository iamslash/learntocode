# Problem

[Fruit Into Baskets](https://leetcode.com/problems/fruit-into-baskets/)

# Idea

과일의 종류를 의미하는 숫자의 모음 `A[]` 가 주어진다. 바구니는 두개
있다. 각 바구니에는 한 종류의 과일만 무한히 넣을 수 있다. 연속된
나무들 중 가장 많은 과일을 두개의 바구니에 담을 수 있는 경우 그
나무들의 개수를 구하는 문제이다.

전형적인 two pointers 문제이다. `unordered_map<int, int> cnts` 를
선언하고 `과일종류: 과일개수` 를 저장한다. 인덱스 `i, j` 를 이용하여
`A[]` 를 처음부터 순회한다. `cnts.size() <= 2` 일 때 최대의 `j-i` 값을
구하면 답이된다.

이 때 `j - i` 가 줄어들 경우는 고려하지 말고 늘어날 경우만 고려한다면
최대값을 특별히 저장하지 않고 모든 반복이 끝난 후 `j - i` 가 답이된다.

다음은 `A = (3, 3, 1, 3, 1, 2, 3)` 의 풀이 과정이다.

```
                       i                i                i
   A: 3 3 1 2 1 2 3    3 3 1 2 1 2 3    3 3 1 2 1 2 3    3 3 1 2 1 2 3
                       j                  j                  j
cnts:                  3                3                3 1
                       1                2                2 1

        i                  i                i                  i
   A: 3 3 1 2 1 2 3    3 3 1 2 1 2 3    3 3 1 2 1 2 3    3 3 1 2 1 2 3
            j                  j                  j                  j
cnts: 3 1 2            1 2              1 2               1 2 3
      1 1 1            2 1              2 2               1 2 1
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
