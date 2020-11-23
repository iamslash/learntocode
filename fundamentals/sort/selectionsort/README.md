# Problem

수열 `V` 가 주어지면 selection sort 를 
이용하여 정렬하자.

# References

* [Selection Sort @ geeksforgeeks](https://www.geeksforgeeks.org/selection-sort/)

# Idea

`V` 의 최소값 `mi` 를 찾는다.
그 값을 맨 앞에 위치한 값과 교체한다.
맨 처음 위치를 뺀 나머지 리스트를 같은 방법으로 교체한다.

다음은 수열 `V = 1 5 4 3 2` 를 selection sort 하는 과정이다.

```
mi: 0        mi: 0        mi: 0        mi: 0

i j          i   j        i     j      i       j
1 5 4 3 2    1 5 4 3 2    1 5 4 3 2    1 5 4 3 2

mi: 2        mi: 3        mi: 4        mi: 4

  i j          i   j        i     j      i     j
1 5 4 3 2    1 5 4 3 2    1 5 4 3 2    1 2 4 3 5

mi: 3        mi: 3        mi: 3        mi: 3

    i j          i   j        i   j          i j
1 2 4 3 5    1 2 4 3 5    1 2 3 4 5    1 2 3 4 5
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2) O(1)
```
