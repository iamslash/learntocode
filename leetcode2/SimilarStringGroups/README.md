# Problem

[Similar String Groups](https://leetcode.com/problems/similar-string-groups/)

문자열의 모음 `A[]` 가 주어진다. `A[i]` 는 길이가 모두 같고 anagram
이다. 즉, 문자의 종류와 개수가 같다. `A[i]` 와 `A[j]` 가 정확히
한문자씩 서로 교환하면 같아질 때 similar 하다고 하자.  서로 smilar 한
문자열을 한 group 에 배치할 때 그 group 의 개수를 구하라.

# Idea

예를 들어, `A = ["tars","rats","arts","star"]` 를 살펴보자.

```
     group  
tars     0
rats     0
arts     0
star     1
```

따라서 답은 2 이다.

[DisjointSet](/fundamentals/disjointset/unionfind/README.md) 을
이용하여 해결할 만 하다. `DisjointSet ds` 을 선언하여 group 의 개수를
구하는데 이용한다.  함수 `bool similar(const char& a, const char& b)`
를 선언하여 `a, b` 가 비슷한지 판단한다.

인덱스 `i, j` 를 이용해서 `A[]` 를 순회하며 다음을 반복한다.

* `similar(A[i], A[j])` 이면 `ds.merge(A[i], A[j]` 를 수행한다.

모든 반복을 마치면 `ds.group()` 를 리턴한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2W) O(N)
```
