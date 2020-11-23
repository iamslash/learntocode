# Problem

[Range Module](https://leetcode.com/problems/range-module/)

# Idea

`map<int, int, greater<int>> data` 를 선언하여 `{start, end}` 를
저장한다. `Compare` 가 `greater<int>` 이므로 내림차순으로 정렬된다.

`addRange(left, right)` 는 `left, right` 을 merge 하면서
`data` 에 저장한다.

```
addRange(10, 20)
data: 10
      20
      
addRange(15, 30)
data: 10
      30
```

`queryRange(left, right)` 를 살펴보자. `data` 는 이미 내림차순으로 
정렬되어 있다. `it = data.lower_bound(left)` 를 수행한다. `left`
보다 작거나 같은 key 를 찾는다. 없다면 false 를 리턴한다. 있다면
`right <= it->second` 를 리턴한다.

```
queryRange(15, 20)
data: 10
      30
```

`removeRange(left, right)` 를 살펴보자. 

```
removeRange(15, 25)
            it
data: 25 10 
      30 15
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
   addRange: O(N)   O(N)
 queryRange: O(lgN) O(N)
removeRange: O(N)   O(N)
```
