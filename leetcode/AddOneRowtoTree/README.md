# Problem

* [Add One Row to Tree](https://leetcode.com/problems/add-one-row-to-tree/)

# Idea

가능한 모든 경우를 생각해 보고
재귀적으로 해결한다.

* 노드의 개수가 0 인 경우는 없다.

* 노드의 개수가 1 인 경우. 

```
    4        
v=1, d=1       

    1
   / 
  4
```

```
    4        
v=1, d=2

    4
   / \ 
  1   1
```

* 노드의 개수가 2 인 경우

```
    4
   /
  2        
v=1, d=1       

      1
     /
    4
   /
  2        
```

```
    4
   /
  2        
v=1, d=2       

      4
     / \
    1   1
   /
  2        
```

* 노드의 개수가 3 인 경우

```
    4
   / \ 
  2   3    
v=1, d=1       

      1
     /
    4
   / \
  2   3     
```

```
    4
   / \
  2   3     
v=1, d=2

      4
     / \
    1   1
   /     \
  2       3 
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```