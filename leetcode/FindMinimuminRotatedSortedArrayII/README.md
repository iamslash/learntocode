# Problem

* [Find Minimum in Rotated Sorted Array II](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/)

# Idea

정렬된 후 자리를 이동한 수열 `V` 가 주어진다. 가장 작은 숫자 `a` 를 찾는 문제이다. 숫자는 중복이 허용됨을 유의하자. binary search 를 이용하여 해결한다.

binary search 를 위해 인덱스 `l, m, r` 을 사용한다. 이때 `a` 의 위치에 따라 다음과 같은 몇가지 경우를 살펴보자.

첫째 `a` 가 `V[l] ~ V[m]` 에 있는 경우 `V[m] <= V[r]` 이다.

```
V[l] ? ? a ? ? V[m] ? ? V[r]
```

둘째 `a` 가 `V[m] ~ V[r]` 에 있는 경우 `V[m] >= V[r]` 이다.

```
V[l] ? ?  V[m] ? ? a ? ? V[r]
```

위의 사실들을 통해서 다음과 같은 몇가지 방법을 생각할 수 있다.

* `V[m] > V[r]` 이면 `V[m] ~ V[r]` 에 최소값이 있다는 의미이다. `l = m + 1` 한다.
* `V[m] < V[r]` 이면 `V[l] ~ V[m]` 에 최소값이 있다는 의미이다. `r = m` 한다.
* `V[m] < V[r]` 이면 `V[m] ~ V[r-1]` 에 최소값이 있다는 의미이다. `r--` 한다.

문제를 단순히 하기 위해 다음과 같은 4 가지 경우를 생각해보자.

* `3 1 2`

```
         m          l
l m r    l r        r
3 1 2    3 1 2    3 1 2
```

* `1 2 3`

```
         m         l
l m r    l r       r
1 2 3    1 2 3    1 2 3
```

* `2 3 1`

```
             l
l m r        r
2 3 1    2 3 1
```

* `2 2 2`

```
         m        l
l m r    l r      r
2 2 2    2 2 2    2 2 2
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(lgN) O(1)
```
