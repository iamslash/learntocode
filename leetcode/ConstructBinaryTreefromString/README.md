# Problem

[Construct Binary Tree from String](https://leetcode.com/problems/construct-binary-tree-from-string/)

# Idea

문자열 `s` 가 주어지면 트리를 생성하는 문제이다.

멤버변수 `int m_i` 를 선언하고 `s` 를 순회하는데 사용한다.
다음과 같이 부분문제 `solve` 를 정의한다.

```cpp
TreeNode* solve(string& s);
```

다음은 `s = 4(2(3)(1))(6(5))` 에 대한 recursion tree 이다.

```
                      s("4(2(3)(1))(6(5))")
                      /                   \
         s("2(3)(1))(6(5))")              s("6(5))")
          /               \                   /
   s("3)(1))(6(5))")  s("1))(6(5))")    s("5))")
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
