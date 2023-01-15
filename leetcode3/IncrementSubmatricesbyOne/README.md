# Problem

[Increment Submatrices by One](https://leetcode.com/problems/increment-submatrices-by-one/)

숫자 `n`, 이차원 수열 `queries[][]` 가 주어진다.
`n X n` 크기의 matrix 가 있다고 해보자. 초기값은
`0` 이다. `queries[i] = [r1, c1, r2, c2]` 
이다. `matrix[r1][c1]` 부터 `matrix[r2][c2]`
까지 `1` 을 더한다. `queries[][]` 를 모두
적용하고 나서 `matrix` 를 구하라.

# Idea

예를 들어 `n = 3, queries = [[1,1,2,2],[0,0,1,1]]` 을 살펴보자.

```


0 0 0    0 0 0    1 1 0
0 0 0    0 1 1    1 2 1
0 0 0    0 1 1    0 1 1
```

따라서 답은 가장 오른쪽의 matrix 와 같다.

만약 다음과 같은 range caching 이 있다고 해보자. matrix
를 벗어난 값은 사용되지 않을 것이다.

```
1 0 -
0 1 0 -
- 0 1 -
  -   1
```

이제 range caching 을 가지고 가로로 
prefix sum 을 해보자.

```
1 0 -    1 1 0
0 1 0    0 1 1
- 0 1    - - 0
```

이번에는 range caching 을 가지고 세로로
prefix sum 을 해보자.

```
1 1 0    1 1 0
0 1 1    1 2 1
- - 0    0 1 1
```

역시 앞서 계산한 답과 같다. 그렇다면 range caching 은 어떻게 구할까?
`r1, c1, r2, c2` 가 주어졌을 때 다음을 수행하여 range caching 을 구한다.

```
matrix[r1][c1]         += 1
matrix[r1][c2 + 1]     -= 1
matrix[r2 + 1][c1]     -= 1
matrix[r2 + 1][c2 + 1] += 1
```

다음은 `n = 3, queries = [[1,1,2,2],[0,0,1,1]]` 의 경우
range caching 을 구하는 과정이다.

```
        
0 0 0    0 0 0      1 0 -
0 0 0    0 1 0 -    0 1 0 -
0 0 0    0 0 0      - 0 1
           -   1      -   1
```

# Implementation

* [java11](MainApp.java)

# Complexity

```
O(HW) O(HW)
```
