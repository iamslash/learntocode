# Problem

[Ternary Expression Parser](https://leetcode.com/problems/ternary-expression-parser/)

# Idea

멤버변수 `int m_i` 를 증가하면서 재귀적으로 해결한다. 

`T?T:F?T?1:2:F?3:4` 에 대한 recursion tree 는 다음과 같다.

```          
                   T?T:F?T?1:2:F?3:4(T)
                     /       \
        T:F?T?1:2:F?3:4(T)  F?T?1:2:F?3:4(4)
                                /       \
                     T?1:2:F?3:4(1)    F?3:4(4)
                          /     \
                 1:2:F?3:4(1)   2:F?3:4(2)                       
                                    
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
