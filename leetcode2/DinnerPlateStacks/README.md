# Problem

[Dinner Plate Stacks](https://leetcode.com/problems/dinner-plate-stacks/)

# Idea

`map<int, vector<int>> stckMap` 을 선언하여 인덱스별 스택을
저장한다. 즉, `{idx: [val,...]}` 를 저장한다. `set<int> freeSet` 을
선언하여 삽입가능한 stack 의 인덱스를 저장한다. 즉, `{idx}` 를
저장한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
      push: O(1) O(N)
       pop: O(N) O(N)
popAtStack: O(1) O(N)
```
