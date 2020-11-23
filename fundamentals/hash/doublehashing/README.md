# Abstract

- open addressing 은 `key, val` 이 주어지면 hash collision 이 발생했을 때 배열의 사용하지 않는 공간에 저장하는 방법을 말한다. open addressing 은 사용되지 않는 공간을 검색하는 방법에 때라 linear probing, Quadratic probing, double hashing 등이 있다.
- double probing 은 hash collision 이 발생했을 때 한번 더 `hash(index)` 하여 unused space 를 찾는다.

# References

* [Double Hashing @ geeksforgeeks](https://www.geeksforgeeks.org/double-hashing/)

# Algorithm Insert

## Idea

`key, val` 이 주어지면 `idx = hash(key)` 가 비어 있는지 확인한다.
`idx` 가 이미 사용되었다면 `idx2 = hash2(key), i = 1` 를 하고 
`nidx = (idx + i * idx2) % m_hash.size()` 를 탐색한다. 
`nidx` 역시 이미 사용되었다면 `i` 를 하나씩 증가하면서 probing 한다.

## Complexity

```
O(1) O(N)
```

# Algorithm Delete

## Idea

linear probing 과 달리 `key, val` 가 연속으로 저장될 필요가 없다.

## Complexity

```
O(1) O(N)
```

# Implementation

* [c++11](a.cpp)
