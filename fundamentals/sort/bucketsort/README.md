# Problem

수열 `V` 가 주어지면 bucket sort 를 이용하여 정렬하라.

# References

* [Sorting Algorithm | Bucket Sort - step by step guide @ youtube](https://www.youtube.com/watch?v=geVyIsFpxUs)

# Idea

`B` 는 벡터를 원소로하는 `BSIZE` 크기의 자료구조이다. 버킷들의
모음이다.  `V` 의 최대값을 `maxv` 에 저장한다.  그리고 다음과 같이
버킷의 인덱스를 계산하기 위한 피연산자 `div` 를 다음과 같이 구한다.

```
div = ceil((maxv + 1) / BSIZE);
```

크기 `b` 의 버킷들 `vector<int> B[b]` 를 생성한다.  `V[i]` 를 `B[j]`
에 삽입한다. `j` 는 다음과 같이 구한다.

```
j = V[i] / div
```

인덱스 `i` 를 이용하여 `B` 를 순회하면서 벡터 `B[i]` 를 정렬한다. 그때
인덱스 `j` 를 이용하여 `B[i]` 를 순회하면서 `V[k++] = B[i][j]` 를
수행한다.

다음은 수열 `V = 8 4 7 1 3 5` 를 bucket sort 하는 과정이다.
`BSIZE = 3, div = 3` 이다.

```
V: 8 4 7 1 3 5    1 4 7 1 3 5    1 3 4 5 7 5    1 3 4 5 7 8

B: 0: 1         i 0: 1           0: 1           0: 1
   1: 4 7 3 5     1: 4 7 3 5   i 1: 3 4 5 7     1: 3 4 5 7
   2: 8           2: 8           2: 8         i 2: 8
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
