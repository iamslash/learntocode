# Problem

* [Trapping Rain Water
 @ leetcode](https://leetcode.com/explore/interview/card/top-interview-questions-hard/124/others/875/)

# Idea

시작상태

```
        *
    *   ** *
  * ** ******
  l          
            r
 m
             M  
rslt: 0
```

종료상태

```
        *
    *   ** *
  * ** ******
        l          
        r
        m
         M  
rslt: 6
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N), O(1)
```
