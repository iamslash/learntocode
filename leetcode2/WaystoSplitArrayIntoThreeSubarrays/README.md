# Problem

[Ways to Split Array Into Three Subarrays](https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/submissions/)

수열 `nums[]` 가 주어진다. 3 개의 subarray `a[], b[], c[]` 로 나누어
보자. 그리고 `sum(a) <= sum(b) <= sum(c)` 가 되도록 하자.  이때 그
경우의 수를 구하라.

# Idea

예를 들어 `nums = [1,2,2,2,5,0]` 의 경우를 살펴보자.

```
[1] [2] [2,2,5,0]
[1] [2,2] [2,5,0]
[1,2] [2,2] [5,0]
```

따라서 답은 3 이다.

[partial sum](/fundamentals/partialsum/partialsum/README.md) 을 이용하여 해결할 만 하다.

`nums[]` 를 [partial sum](/fundamentals/partialsum/partialsum/README.md) 으로 하면 space complexity 를 아낄 수 있다.

예를 들어 `nums = [1,2,2,2,5,0]` 의 경우를 다시 살펴보자. 인덱스 `i, j, k` 를 선언한다. `i` 를 `[0..n-2]` 만큼 순회하면서 `j, k` 의 후보를 생각해보자.

```
i
1 2 2 2 5 0
    j
        k

  i
1 2 2 2 5 0
      j
          k

    i
1 2 2 2 5 0
        j
            k
```

각 `i` 에 대해 `k - j` 를 합하면 답이 된다.

# Implementation

* [java8](Solution.java)

# Complexity

```
O(N) O(1)
```

# Similar Questions

* [Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)
