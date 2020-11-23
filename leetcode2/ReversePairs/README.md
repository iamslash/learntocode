# Problem

[Reverse Pairs](https://leetcode.com/problems/reverse-pairs/)

수열 `A[]` 가 주어진다. `i < j` 일 때 `A[i] > 2 * A[j]` 를
만족하는 `(i, j)` 의 개수를 구하라.

# Idea

예를 들어 `A = [1, 3, 2, 3, 1]` 인 경우를 살펴보자.

1. 먼저 두 그룹으로 나눈다. 
2. 그리고 각각 오름차순으로 정렬한다. 
3. 앞 그룹의 숫자들은 뒤 그룹의 숫자들보다 인덱스가 모두 작다. 이제 앞
그룹의 숫자를 하나 정하면 문제의 조건을 만족하는 뒤 그룹의 숫자들을
쉽게 찾을 수 있다.

```
* divide
1 3 2    3 1

* sort
1 2 3    1 3

* count
  i
1 2 3    1 3
         j         

    i
1 2 3    1 3
         j    
```

각 그룹에 대해 1 - 3 까지 반복한다.

```
* divide
1 2    3

* sort 
1 2    3

* count
1 2    3
```

```
* divide
1    3

* sort
1    3

* count
1    3
```

이것은 divide and conquer 이다. merge sort 와 매우 비슷하다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(lgN)
```
