# Problem

* [Smallest Range](https://leetcode.com/problems/smallest-range/)

# References

* [Shortest Range in K sorted lists @ youtube](https://www.youtube.com/watch?v=Fqal25ZgEDo)

# Idea

정렬된 `K` 개의 수열들 `L` 이 주어졌다고 하자. 각 리스트마다
최소한 한개씩은 포함하는 최소 범위 `[a,b]` 를 찾는 문제이다.

```
4 10 15  24 26
0  9 12 20
5 18  22 30
```

각 수열의 처음을 가리키는 인덱스들을 저장하자.
그 때의 범위를 `rslt` 에 저장한다. 그리고 다음을 반복한다.

가장 작은 수를 가리키는 인덱스를 한칸 전진하고
최소범위를 `rslt` 에 저장한다.

하나의 인덱스가 리스트의 끝까지 순회했다면 `rslt` 가
답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(KNlgN) O(N)
```
